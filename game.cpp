#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#define SIZE 20

using namespace std;

/*
Variables
    guesses - string[]
    found - bool = false
    magic_no - int
    N - int[]
    P - int[]
    guess_str - string
    magic_str - string

Loops/Validations
    do-while -> validating the user's guess
        4 digit mehonun
        repetition alenemorun

    for -> comparing the user's guess with the magic number
        to calculate N of the guess
        to calculate P of the guess

    for -> displaying the table
        to go through the guess array
        to go through the N & P arrays
*/

int main(){
    
    // This is the string we use to store our user's guess history.
    string guesses[SIZE];

    // This the string we use to input our user's guesses.
     string guess_str;

    // This is the string we use to store the generated secret number.
     string  magic_str;

    // This is used to store the number of correct digits there are in the user's guess.
    int N[SIZE];

    // This is used to store the number of correct positions of the digits in the user's guess.
     int P[SIZE];

    // This is used to store the number of guesses the user inputs.
      int num_of_guesses(0); 

    // This the width between  the coulums. 
     int  col_width (10);

    /* This is a boolean variable that tell whether or not the number has been correctly guessed. 
     Note that it is set to false.
    */ 
    bool found = false;

    // This is a boolean value that we use to validate the user's guess.
    bool valid_input=true;

    // This is a boolean value that we use to check if the random number genreated is valid. 
    bool valid_magic_no=true;

    //This is the character we use to beautify our table.
    char special_char = '-';
    
    //Generate a valid random number with no repetitions.
    do{
        srand (time(NULL));
        magic_str = to_string(rand() % 9999 + 1000);
        for (int i = 0; i < 3 && valid_magic_no ; i++){

            //Repetition alemnorun
            for (int j = i+1; j < 4; j++){
                if(magic_str[i] == magic_str[j]){
                    valid_magic_no = false;
                    break;
                }
            }
        }     
    } while (!valid_magic_no);
        
    
    //Code for displaying the game's rules in a very graphic manner.
    
    cout<<"Hello! Welcome to our number guessing game!\n\n";
    cout<<"You have to guess a four digit number that we will randomly generate. After every attempt, you will see the score.\n\n";
    cout<<"Rules of the game: \n\n 1. You cannot repeat digits in your guess. \n 2. Your guess must be exactly 4 digits long.\n";
    
    cout << left;
    cout << setfill(special_char) << setw(3*col_width) << special_char << endl;
    //Header row 
    cout << setfill(' ');
    cout << setw(col_width) << "Guesses";
    cout << setw(col_width) << "N";
    cout << setw(col_width) << "P";
    cout << endl;
    //Divider row
    cout << setfill(special_char) << setw(3*col_width) << special_char << endl;

    cout <<" \n'N' tells you how many digits you guessed correctly.";
    cout <<" \n'P' tells you how many of the correctly guessed digits are in the right position.";
    cout << "\n\nThe goal is to get a score of 4 for N and P.\n\n";
    cout << "Good Luck!\n";
    
    do{//Until it's found

        do{//For validating the user's input
            valid_input = true;
            cout << "\nYour guess: ";
            cin >> guess_str;

            //4 digit mehonun
            if (guess_str.size() != 4){
                cout << "\nTey baba. Your guess has to be exactly four digits. Try again.";
                valid_input = false;
            }
            
            //Repetition alemenorun and 
            //That it's only a positive number.
            for (int i = 0; i < 4 && valid_input ; i++){
                //Digit mehonun
                if(guess_str[i] < '0' || guess_str[i] > '9'){
                    cout<< "Asemam inde. No characters except numbers.";
                    valid_input = false;
                    break;
                }

                //Repetition alemnorun
                for (int j = i+1; j < 4; j++){
                    if(guess_str[i] == guess_str[j]){
                        valid_input = false;
                        cout << "\nTey baba. You can't repeat digits.";
                        break;
                    }
                }
            }

        }while(!valid_input);

        //Store user's input in guesses[] array
        guesses[num_of_guesses] = guess_str;

        //For comparing the user's guess with the magic number
        N[num_of_guesses] = 0;
        P[num_of_guesses] = 0;
        for (int i = 0; i < 4; i++){

            //For calculating the N of each guess.
            for (int j = 0; j < 4; j++){
                if(magic_str[i] == guess_str[j]){
                    N[num_of_guesses]++;
                }
            }

            //For calculating the P of each guess.
            if(magic_str[i] == guess_str[i]){
                P[num_of_guesses]++;
            }
        }

        //For displaying all accumulated guesses, N & P
        cout << left;
        cout << setfill(special_char) << setw(3*col_width) << special_char << endl;
        //Header row 
        cout << setfill(' ');
        cout << setw(col_width) << "Guesses";
        cout << setw(col_width) << "N";
        cout << setw(col_width) << "P";
        cout << endl;
        //Divider row
        cout << setfill(special_char) << setw(3*col_width) << special_char << endl;
        
        for (int i = 0; i <= num_of_guesses; i++){
            cout << setfill(' ');
            cout << setw(col_width) << guesses[i];
            cout << setw(col_width) << N[i];
            cout << setw(col_width) << P[i];
            cout << endl;
        }

        if(P[num_of_guesses]==4 && N[num_of_guesses]==4){
            found=true;
            cout << "|---------------------------------------|"<<endl;
            cout << "|CONGRATES!! You have found the number!!|"<<endl;
            cout << "|---------------------------------------|";
        }
        if(num_of_guesses > 20){
            cout << "\nYou've reached the maximum of " << SIZE << "guesses! Tebelah.";
        }
        
        num_of_guesses++; //Increment the variable holding the number of guesses.

    }while(!found && num_of_guesses <= 20);
  
    return 0;
}
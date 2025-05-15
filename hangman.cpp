#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void game_Rules();
string category_choice();
void read_File(const int, ifstream &, string[]);
int rand_Word(const string[], char[]);
int hang_Body(int, const string[], int);
void guess_Word(const string[], char[], int &);

int main()
{
    char choice1;
    string category;
    const int Total_words = 15;
    const int Total_blanks = 15;
    string file_array[Total_words];

    unsigned seed = time(0);
    srand(seed);

    game_Rules();
    category = category_choice();

    ifstream Actual_File;
    Actual_File.open(category);

    int word_no;
    char no_of_blanks[Total_blanks];
    char ch2;

    read_File(Total_words, Actual_File, file_array);

    do
    {
        word_no = rand_Word(file_array, no_of_blanks);
        guess_Word(file_array, no_of_blanks, word_no);
        cout << "\nDo you want to play again?(press y or Y)";
        cin >> ch2;

        system("cls");
    } while (ch2 == 'y' || ch2 == 'Y');

    Actual_File.close();

    return 0;
}
void game_Rules()
{
    char ch1;
    cout << "\t\t\t\t---------WELCOME TO HANGMAN!!!-----------\n\n";
    cout << "\t\t\t\tSo here are the rules:\n";
    cout << "\t\t1. You'll have five categories to choose from.\n";
    cout << "\t\t2. Spaces will be generated according to the word.\n";
    cout << "\t\t3. All you have to do is guess the word.\n";
    cout << "\t\t4. For every incorrect guess, a body part of hangman will be drawn.\n";
    cout << "\t\t5. If the hangman is fully drawn, YOU'RE OUT!!\n\n";
    cout << "\t\t\t. Good Luck, Have Fun!!\n\n\n";
    cout << "\tPress Y to continue to game: ";
    cin >> ch1;

    if (ch1 == 'Y')
        system("cls");
}
string category_choice()
{
    char choice;
    cout << "Press N for nature, S for sports, A for academics, L for love and W for winter.";
    cin >> choice;
    if (choice == 'N' || choice == 'n')
    {
        return "nature.txt";
    }
    if (choice == 'S' || choice == 's')
    {
        return "sports.txt";
    }

    if (choice == 'A' || choice == 'a')
    {
        return "academics.txt";
    }

    if (choice == 'L' || choice == 'l')
    {
        return "love.txt";
    }

    if (choice == 'W' || choice == 'w')
    {
        return "winter.txt";
    }
}
int rand_Word(const string file_array[], char no_of_blanks[])
{
    int rand_word = rand() % 15;
    for (int i = 0; i < file_array[rand_word].length(); i++)
    {
        no_of_blanks[i] = '_';
        cout << no_of_blanks[i] << " ";
    }
    return rand_word;
}
void read_File(const int Total_words, ifstream &Actual_File, string file_array[])
{
    for (int i = 0; i < Total_words; i++)
    {
        getline(Actual_File, file_array[i]);
    }
}
void guess_Word(const string file_array[], char no_of_blanks[], int &word_no)
{
    int counter = 0;
    char choice;
    int i = 0;
    int incor_choice = 0;
    const int total_guesses = 30;

    while (i < total_guesses)
    {
        cout << "\n\nEnter a choice to guess: ";
        cin >> choice;
        int tot_letters = 0;
        bool found = false;

        for (int i = 0; i < file_array[word_no].length(); i++)
        {
            if (file_array[word_no][i] == choice)
            {
                no_of_blanks[i] = choice;
                found = true;
            }
        }
        i++;

        for (int j = 0; j < file_array[word_no].length(); j++)
        {
            if (no_of_blanks[j] != '_')
            {
                tot_letters++;
            }
        }
        system("cls");

        for (int k = 0; k < file_array[word_no].length(); k++)
        {
            cout << no_of_blanks[k] << " ";
        }

        if (!found)
        {
            cout << "\n\nINCORRECT ANSWER!!\n";
            incor_choice++;
        }

        cout << "\n\n\n\n\nHANGMAN FIGURE DISPLAY\n\n\n\n";
        int check = hang_Body(incor_choice, file_array, word_no);
        if (check == -1)
        {
            return;
        }
        if (tot_letters == file_array[word_no].length() && check == 0)
        {
            cout << "\nYou guessed the word!";

            if (incor_choice == 0)
            {
                cout << "\nCONGRATS ON FIRST TRY!!";
            }

            break;
        }
        counter++;
    }
    if (counter >= 30)
    {
        cout << "\n\nYOU FAILED TO GUESS THE WORD!!";
        cout << "\nYour word is: " << file_array[word_no];
    }
}
int hang_Body(int incor_choice, const string file_array[], int word_no)
{
    char head = 'O', left_body = '/', right_body = '\\', body = '|';

    if (incor_choice > 0)
        cout << "\t\t " << head << endl;
    if (incor_choice == 2)
        cout << "\t\t " << body;
    else if (incor_choice > 2)
        cout << "\t\t" << left_body << body;
    if (incor_choice > 3)
        cout << right_body << endl;
    if (incor_choice > 4)
        cout << "\t\t" << left_body;
    if (incor_choice > 5)
        cout << " " << right_body;
    if (incor_choice > 6)
    {
        cout << "\n\nYOU FAILED TO GUESS THE WORD!!";
        cout << "\nYour word is: " << file_array[word_no];

        return -1;
    }
    return 0;
}
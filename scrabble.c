#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins\n");

    }
    else if (score2 > score1)
    {
        printf("Player 2 wins\n");

    }
    else
    {
        printf("Tie\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    int i = 0;
    int n = strlen(word);


    for (i = 0; i < n; i++)
    {
        //CS50 manual pages
        char c = word[i];
        //Check only for alphabetical characters
        if (isalpha(c))
        {
            if (islower(c))
            {
                //Get position of character
                //ASCII lowercase a = 97; so if its a then its 97 - 97 which will give you position 0, b is 98 - 97 which will give you position 1.
                int position = c - 'a';

                //Keep track of the score
                score += POINTS[position];
            }
            else
            {
                int position = tolower(c) - 'a';

                //Keep track of the score
                score += POINTS[position];
            }
        }
    }
    return score;
}
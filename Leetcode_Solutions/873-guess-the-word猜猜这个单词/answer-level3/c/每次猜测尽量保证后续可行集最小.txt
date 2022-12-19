```
/**
 * *********************************************************************
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int guess(Master *, char *word);
 */
#define MAX_LETTER_NUM 6
void ComputeMatch(char** wordlist, int wordlistSize, int** matchCNum)
{
    int i, j, k;
    int match;
    for (i = 0; i < wordlistSize; i++) {
        for (j = i; j < wordlistSize; j++) {
            if (i != j) {
                match = 0;
                for (k = 0; k < MAX_LETTER_NUM; k++) {
                    if (wordlist[i][k] == wordlist[j][k]) {
                        match++;
                    }
                }
                matchCNum[i][j] = match;
                matchCNum[j][i] = match;
            } else {
                matchCNum[i][j] = MAX_LETTER_NUM;
            }
        }
    }
}
int Max(int* num, int size)
{
    int i;
    int max = num[0];
    for (i = 1; i < size; i++) {
        if (max < num[i]) {
            max = num[i];
        }
    }
    return max;
}
int FindNextGuess(char** wordlist, int wordlistSize, bool* guessed, int** matchCNum)
{
    int i, j;
    int guess;
    int candidate;
    int matched[MAX_LETTER_NUM + 1];
    int max;
    int min = INT_MAX;
    for (guess = 0; guess < wordlistSize; guess++) {
        if (!guessed[guess]) {
            memset(matched, 0, sizeof(matched));
            for (i = 0; i < wordlistSize; i++) {
                if (i != guess && !guessed[i]) {
                    matched[matchCNum[guess][i]]++;
                }
            }
            max = Max(matched, MAX_LETTER_NUM + 1);
            if (min > max) {
                min = max;
                candidate = guess;
            }
        }
    }
    return candidate;
}
void findSecretWord(char** wordlist, int wordlistSize, Master* master) {
    bool* guessed = (bool*)malloc(wordlistSize * sizeof(bool));
    int guessedMany = 0;
    memset(guessed, false, wordlistSize * sizeof(bool));
    int** matchCNum = (int**)malloc(wordlistSize * sizeof(int*));
    int i;
    for (i = 0; i < wordlistSize; i++) {
        matchCNum[i] = (int*)malloc(wordlistSize * sizeof(int));
    }
    int candidate;
    int num;
    ComputeMatch(wordlist, wordlistSize, matchCNum);
    while (guessedMany < wordlistSize) {
        candidate = FindNextGuess(wordlist, wordlistSize, guessed, matchCNum);
        guessed[candidate] = true;
        num = guess(master, wordlist[candidate]);
        if (num == MAX_LETTER_NUM) {
            break;
        }
        for (i = 0; i < wordlistSize; i++) {
            if (!guessed[i] && matchCNum[candidate][i] != num) {
                guessed[i] = true;
            }
        }
    }
}
```
基本上目前看就一个思路，但是官方题解感觉有点小瑕疵。

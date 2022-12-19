bool validWordSquare(char ** words, int wordsSize)
{
    int len;

    for (int i = 0; i < wordsSize; i++) {
        len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            if (j >= wordsSize) {
                return false;
            }

            if (i > strlen(words[j])) {
                return false;
            }

            if (words[i][j] != words[j][i]) {
                return false;
            }
        }
    }
    return true; 
}
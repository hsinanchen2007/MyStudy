```
int compVote(int* v1, int n1, int* v2, int n2, int n)
{
    for (int i = 0; i < n; i++) {
        if (v1[i] > v2[i]) return 1;
        else if(v1[i] < v2[i]) return -1;
        else continue;
    }
    return 0;
}

void sortChar(int** voteChar, int row, int col)
{
    for (int i = 1; i < row; i++) {
        int t = i;
        for (int j = t - 1; j >= 0; j--, t--) {
            if (compVote(voteChar[t], t, voteChar[j], j, col) == 1) {
                int* tmp = voteChar[t];
                voteChar[t] = voteChar[j];
                voteChar[j] = tmp;
            }
        }
    }
}

char * rankTeams(char ** votes, int votesSize) {
    int n = strlen(*votes);
    
    int** voteChar = (int**)malloc(26 * sizeof(int*));
    for (int i = 0; i < 26; i++) {
        voteChar[i] = (int*)malloc((n + 1) * sizeof(int));
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            voteChar[i][j] = -1;
        }
    }
    
    for (int i = 0; i < votesSize; i++) {
        int j = 0;
        while (votes[i][j] != '\0') {
            char ch = votes[i][j];
            voteChar[ch - 'A'][n] = 26 - (ch - 'A');
            ++voteChar[ch - 'A'][j];
            ++j;
        }
        
    }
    
    int row = 26;
    int col = n + 1;
    sortChar(voteChar, row, col);
    
    char* res = (char*)malloc(n + 1);
    
    for (int i = 0; i < n; i++) {
        res[i] = 26 - voteChar[i][n] + 'A';
    }
    res[n] = '\0';
    for (int i = 0; i < 26; i++) {
        free(voteChar[i]);
    }

    
    return res;
}
```

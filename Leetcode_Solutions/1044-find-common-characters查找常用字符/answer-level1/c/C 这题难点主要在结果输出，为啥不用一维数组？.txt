char ** commonChars(char ** A, int ASize, int* returnSize){
    int time[26] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
    int temp[26] = {0};
    int sum = 0;
    int num = 0;
    for (int i = 0; i < ASize; i++){
        for (int j = 0; j < strlen(A[i]); j++){
            temp[A[i][j] - 'a'] += 1;
        }
        for (int k = 0; k < 26; k++){
            if (temp[k] < time[k]){
                time[k] = temp[k];
            }
            temp[k] = 0;
        }
    }
    for (int i = 0; i < 26; i++){
        sum += time[i];
    }
    char ** re = (char **)malloc(sizeof(char *)*sum);
    *returnSize = sum;
    for (int i = 0; i < 26; i++){
        if (time[i] > 0){
            for (int j = num; j < num + time[i]; j++){
                char *q = (char *)malloc(sizeof(char)*2);
                q[0] = 'a' + i;;
                q[1] = '\0';             
                re[j] = q;
            }
            num += time[i];
        }
    }   
    return re;
}
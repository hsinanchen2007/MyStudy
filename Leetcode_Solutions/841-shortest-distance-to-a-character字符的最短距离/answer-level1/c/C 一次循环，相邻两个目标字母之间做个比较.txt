int* shortestToChar(char * S, char C, int* returnSize){
    int head = 0;
    int Ca = -10001;
    int Cb = 10001;
    int * re = (int *)malloc(sizeof(int)*strlen(S));
    for (int i = 0; i < strlen(S); i++){
        if (S[i] == C){
            Cb = i;
            re[i] = 0;
            for (int j = head; j < Cb; j++){
                if ((j - Ca) > (Cb - j)){
                    re[j] = Cb - j;
                } else {
                    re[j] = j - Ca;
                }
            }
            Ca = Cb;
            head = Cb + 1;
        }
    }
    for (int i = Ca; i < strlen(S); i++){
        re[i] = i - Ca;
    }
    *returnSize = strlen(S);
    return re;
}
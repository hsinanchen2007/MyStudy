/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * S, int* returnSize){
    int * cut = (int *)malloc(sizeof(int)*26);
    int numCut = 0;
    int label[26][3] = {0};
    int temp;
    for (int i = 0; i < strlen(S); i++){
        temp = S[i] - 'a';
        if (label[temp][2] == 0){
            label[temp][0] = i;
            label[temp][2] = 1;
        }
        label[temp][1] = i;
    }
    for (int j = 1; j <= strlen(S); j++){
        temp = 0;
        for (int k = 0; k < 26; k++){
            if (label[k][2] > 0){
                if (label[k][0] < j && label[k][1] >= j){
                    temp = 1;
                    printf("alpha:%d cut:%d between %d and %d\n",k,j,label[k][0],label[k][1]);
                    break;
                }
            }
        }
        if (temp == 0){
            cut[numCut] = j;
            numCut++;
        }

    }
    for (int i = numCut - 1; i > 0; i--){
        cut[i] = cut[i] - cut[i - 1];
    }
    *returnSize = numCut;
    return cut;

}
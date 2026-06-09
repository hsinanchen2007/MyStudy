/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


unsigned char g_total[256] = {0};



unsigned char getNext(unsigned char  num){
    unsigned char a = num>>1;
    unsigned char b = num<<1;
    unsigned char c = ((~(a|b))|(a&b))&126;
    //printf("%o, %o, %o, %o\n", num, a, b,c);
    return c;
}


int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){

    unsigned char temp = 0;
    for (int i =0; i<cellsSize; i++){
        temp = (temp<<1)|cells[i];
    }

    unsigned char first = getNext(temp);
    temp =  first;
    int i;
    bool bBreak = false;
    for (i=1; i<N; i++){
        if (g_total[temp] == 0){
            g_total[temp] = getNext(temp);
        }
        temp = g_total[temp];
        if (first == temp){
            bBreak =  true;
            break;
        }
    }
    //printf("i = %d temp = %o\n", i, temp);
    if (bBreak  == true){
        for(int j=0; j<(N-1)%i; j++){
            temp = g_total[temp];
        }
    }


    *returnSize =cellsSize;
    int * result = (int*)malloc(sizeof(int)*cellsSize);
    for(int i= cellsSize-1; i>=0; i--){
        result[i] = temp&1;
        temp = temp>>1;
    }
    return result;
}
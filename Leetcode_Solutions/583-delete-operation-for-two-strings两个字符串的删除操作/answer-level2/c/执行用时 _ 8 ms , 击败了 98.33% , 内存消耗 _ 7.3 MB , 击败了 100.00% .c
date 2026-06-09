int minDistance(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if (len1==0 || len2==0) return len1+len2;
    int *nums = (int *)malloc(sizeof(int) * len2);
    if (word1[0]==word2[0]) nums[0]=1;
    else nums[0]=0;
    for (int i=1; i<len2; i++)
    {
        nums[i] = nums[i-1];
        if (word1[0]==word2[i]) nums[i]=1;
    }
    
    int *tmp = (int *)malloc(sizeof(int) * len2);
    for (int i=1; i<len1; i++){
        tmp[0] = nums[0];
        if (word1[i]==word2[0]) tmp[0]=1;
        for(int j=1; j<len2; j++){
            int x = nums[j], y = tmp[j-1];
            int z = nums[j-1];
            if (word1[i]==word2[j]) z=z+1;
            tmp[j] = max(x, y, z);
        }
        for(int j=0; j<len2; j++) nums[j]=tmp[j];
    }
    return len1+len2-2*nums[len2-1];
}
int max(int x, int y, int z){
    if (x>y && x>=z) return x;
    if (y>=x && y>=z) return y;
    return z;
}
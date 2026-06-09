```
int minDistance(char * word1, char * word2){
    int i=strlen(word1);
    int j=strlen(word2);
    if(i==0)
    return j;
    if(j==0)
    return i;
    int a,b,h;
    int DJ[i+1][j+1];
    for(h=0;h<=i;h++)
    DJ[h][0]=h;
    for(h=0;h<=j;h++)
    DJ[0][h]=h;
    for(a=1;a<=i;a++)
    for(b=1;b<=j;b++)
    {
        int left=DJ[a-1][b]+1;
        int right=DJ[a][b-1]+1;
        int left_right;
        if(word1[a-1]==word2[b-1])
        left_right=DJ[a-1][b-1];
        else
        left_right=DJ[a-1][b-1]+1;
        //DJ[a][b]=(left>right?right:left)>left_right?left_right:(left>right?right:left);
        int min=left>right?right:left;
        min=min>left_right?left_right:min;
        DJ[a][b]=min;
    }
    return DJ[i][j];
}
```

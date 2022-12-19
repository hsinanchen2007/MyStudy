### 解题思路
1.给出的字符串数组可以重复使用
2.那么我们需要找到能够组成的新的new_bottom，然后对每一个新的new_bottom进行尝试，只要有一个能达到效果那么就可以

### 代码

```c
int test(char *a,char *b){
    if ((a[0]==b[0])&&(a[1]==b[1]))
        return 1;
    return 0;
}
char **magical(char **words,int wordSize,int *returnSize){
    register int num=1;
    for (int i=0;i<wordSize;i++)
        num *= strlen(words[i]);
    char **ans,temp[2];
    int top,x,loop;
    temp[1] = 0;
    ans = (char**)malloc(sizeof(char*)*num);
    ans[0] = (char*)malloc(sizeof(char)*(wordSize+1));
    ans[0][0] = 0; 
    top = 0;
    for (int i=0;i<wordSize;i++){
        x = top;
        for (int j=1;words[i][j];j++){
            for (int k=0;k<=x;k++){
                ans[++top] = (char*)malloc(sizeof(char)*(wordSize+1));
                for (loop=0;ans[k][loop];loop++)
                    ans[top][loop] = ans[k][loop];
                ans[top][loop] = 0;
            }
        }
        for (int j=0;words[i][j];j++){
            temp[0] = words[i][j];
            for (int k=0;k<=x;k++){
                strcat(ans[j*(x+1)+k],temp);
            }
        }
    }
    *returnSize = num;
    return ans;
}
bool pyramidTransition(char * bottom, char ** allowed, int allowedSize){
    int len,x;
    len = strlen(bottom);
    if (len==1)
        return true;
    if (len==2){
        for (int i=0;i<allowedSize;i++)
            if (test(bottom,allowed[i]))
                return true;
        return false;
    }
    char **alternate,temp[3],**new_bottom;
    int top,num;
    alternate = (char**)malloc(sizeof(char*)*(len-1));
    temp[2] = '\0';
    for (int i=0;i<len-1;i++){
        top = -1;
        temp[0] = bottom[i];
        temp[1] = bottom[i+1];
        alternate[i] = (char*)malloc(sizeof(char)*(allowedSize+1));
        for (int j=0;j<allowedSize;j++){
            if (test(allowed[j],temp))
                alternate[i][++top] = allowed[j][2];
        }
        if (top==-1)
            return false;
        alternate[i][++top] = '\0';
    }
    new_bottom = magical(alternate,len-1,&num);
    for (int i=0;i<num;i++){
        if (pyramidTransition(new_bottom[i],allowed,allowedSize)==true)
            return true;
    }
    return false;
}
```
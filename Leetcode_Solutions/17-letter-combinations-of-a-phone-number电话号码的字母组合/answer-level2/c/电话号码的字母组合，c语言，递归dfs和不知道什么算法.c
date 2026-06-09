 //字符串数组赋值如下char s[][] = {"",""}；
 //二维数组的如何malloc

方法一：举个例子说明吧，比如输入“27”，result答案有3*4个字符串，对于第一个字符‘2’直接写四个a四个b四个c，对于字符‘7’就pqrs pqrs pqrs，这个规律画一个树就比较好看出。
```
char ** letterCombinations(char * digits, int* returnSize){
    char *s[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",};
    int a[] = {3,3,3,3,3,4,3,4,};
    int n=1,i=0,j=0,k=0,count=0;
    for(i=0;digits[i]!='\0';i++){
        if(digits[i]=='7' || digits[i]=='9'){
            n *=4;
        }else{
            n *=3;
        }
    }
    if(i == 0){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = n;
    char** result = (char**)malloc(sizeof(char*)*n);//二维数组的malloc，行与行之间不连续。
    for(j=0;j<n;j++){
        result[j] = (char*)malloc(sizeof(char)*(i+1));
        result[j][i] = '\0';//字符串末为0
    }
    count = n;
    for(i=0;digits[i]!='\0';i++){
        k = digits[i]-'0'-2;
        count /= a[k];
       for(j=0;j<n;j++){
           result[j][i] = s[k][(j/count)%a[k]];    //画一棵树就可以看出
       }
    }
    return result;
}
```

方法二：利用递归实现。

```
void letterCombination(int* a,char **s,char *digits,char **result,char *temp,int i,int* returnSize){                
    if(temp[i] == '\0'){
        for(int j=0;j<i;j++){
            result[*returnSize][j] = temp[j];
        } 
        (*returnSize)++;
        return 0;
    }else{
        for(int j=0;j<a[digits[i]-'0'-2];j++){
            temp[i] = s[digits[i]-'0'-2][j];
            letterCombination(a,s,digits,result,temp,i+1,returnSize);
        }
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    char *s[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",};
    int a[] = {3,3,3,3,3,4,3,4,};
    int n=1,i=0,j=0,k=0,count=0;
    for(i=0;digits[i]!='\0';i++){
        if(digits[i]=='7' || digits[i]=='9'){
            n *=4;
        }else{
            n *=3;
        }
    }
    if(i == 0){
        *returnSize = 0;
        return NULL;
    }
    char** result = (char**)malloc(sizeof(char*)*n);//二维数组的malloc，行与行之间不连续。
    for(j=0;j<n;j++){
        result[j] = (char*)malloc(sizeof(char)*(i+1));
        result[j][i] = '\0';//字符串末为0
    }
    char *temp = (char*)malloc(sizeof(char)*(i+1));
    temp[i] = '\0';
    *returnSize = 0;
    letterCombination(a,s,digits,result,temp,0,returnSize);
    return result;
}
```


题目很简单，我们直接从后往前遍历字符串，遇到字母直接分两种情况，分成大小写字母，其他的字符直接保存。
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void generate(char **matrix,int *count,char *item,int index,char *S,int mark)
 {
     if(mark==-1)
     {
         matrix[++(*count)]=(char *)malloc(sizeof(char)*(strlen(S)+1));//插入字符串
         strcpy(matrix[(*count)],item);
        return;
     }
     if(S[mark]>='a'&&S[mark]<='z')
     {
         char temp=S[mark]-32;//小写转大写
         item[index]=temp;
         generate(matrix,count,item,index-1,S,mark-1);
         item[index]=S[mark];//插入小写
         generate(matrix,count,item,index-1,S,mark-1);
     }
     else if(S[mark]>='A'&&S[mark]<='Z')
     {
         char temp=S[mark]+32;//大写转小写
         item[index]=S[mark];//插入小写
         generate(matrix,count,item,index-1,S,mark-1);
         item[index]=temp;
         generate(matrix,count,item,index-1,S,mark-1);
     }
     else{
         item[index]=S[mark];
         generate(matrix,count,item,index-1,S,mark-1);
     }
 }
char ** letterCasePermutation(char * S, int* returnSize){
    int length=strlen(S);
    char *item=(char *)malloc(sizeof(char)*(length+1));
    item[length]='\0';
    char **matrix=(char **)malloc(sizeof(char *)*(5000));//返回的二维字符串

    int index=length-1,count=-1,mark=length-1;
    generate(matrix,&count,item,index,S,mark);
    *returnSize=count+1;
    return matrix;
}
```

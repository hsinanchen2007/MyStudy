### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize){
    int * res=malloc(sizeof(int)*2);
    int total=0;
    for(int i=0;i<strlen(S);i++)
    {
        if(total/100==(total+widths[S[i]-'a'])/100||((total+widths[S[i]-'a'])%100==0))
        total+=widths[S[i]-'a'];
        else
        total=((total/100+1)*100+widths[S[i]-'a']);
    }
    res[0]=total/100+1;
    res[1]=total%100;
    *returnSize=2;
    return res;
}
```
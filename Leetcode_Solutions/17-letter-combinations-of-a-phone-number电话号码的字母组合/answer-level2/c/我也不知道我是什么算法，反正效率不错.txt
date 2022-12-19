![image.png](https://pic.leetcode-cn.com/e4549e42b10e1ea387231fbfb0b455035411ade7796fe2aa112ed0f4b8d82048-image.png)
```
int haopengyou(char c)
{
    if(c=='7') return 4;
    if(c=='9') return 4;
    return 3;
}
char ** letterCombinations(char * digits, int* returnSize){
    int l=strlen(digits),i,j,interval;
    char **ans,se[8][5]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(l==0)
    {
        *returnSize=0;
        return NULL;
    }
    *returnSize=1;
    for(i=0;i<l;i++) (*returnSize)*=haopengyou(digits[i]);
    ans=(char **)malloc((*returnSize)*sizeof(char *));
    interval=*returnSize;
    for(i=0;i<(*returnSize);++i)
    {
        *(ans+i)=(char *)malloc((l+1)*sizeof(char));
        ans[i][l]='\0';
    }
    for(i=0;i<l;++i)
    {
        interval/=haopengyou(digits[i]);
        for(j=0;j<(*returnSize);++j)
        {
            ans[j][i]=se[digits[i]-'2'][(j/interval)%haopengyou(digits[i])];
        }
    }
    return ans;
}
```
举个例子吧，比如"22"，那我就会先开3*3个字符串空间，每个字符串长度3。然后给字符串末尾先放置终止符。随后就是现在每个字符串的第0位写入，写3个a，3个b，3个c；再从第1位写入，写1个a，1个b，1个c……
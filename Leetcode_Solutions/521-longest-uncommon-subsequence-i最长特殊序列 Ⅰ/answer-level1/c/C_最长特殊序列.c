### 解题思路
题目描述的乱七八糟的，看这里: https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/solution/nao-jin-ji-zhuan-wan-by-zlhmyl/
### 代码

```c
int findLUSlength(char * a, char * b){
    int alen=strlen(a),blen=strlen(b);
    if (strcmp(a,b)==0)return -1;
        return alen>blen?alen:blen;
}
作者：zlhmyl
链接：https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/solution/nao-jin-ji-zhuan-wan-by-zlhmyl/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//以下是我自己的————————————————————————————————————————————————————————————————————————————————
/*
int findStrA(char* A,char* B)
{
    int hash[26]={0};
    for(int i=0;B[i]!='\0';++i)
        hash[B[i]-'a']+=1;

    int result=0;
    int n=0;
    for(int i=0;A[i]!='\0';++i)
        if(hash[A[i]-'a']==0)
            ++n;
        else
        {
            result=result>n?result:n;
            n=0;   
        }
    return result > n ? result : n;
}
int findLUSlength(char * a, char * b){
    int A=findStrA(a,b);
    int B=findStrA(b,a);
    if(A==0&&B==0) return -1;
    return A>B?A:B;
}*/
```
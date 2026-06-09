### 解题思路
先写一个子函数用于判断从母串某一位开始是否与子串完全匹配
然后从母串0开始逐位用写好的判断方法来判断是否找到匹配的首位置
注意当母串留下的位置不足以与子串匹配后就可以退出返回-1了

### 代码

```c
bool isSame(char *h, char *n,int first,int len) ;
int strStr(char * haystack, char * needle){
    //可以采用KMP，但先使用常规的一位一位匹配
    if(needle[0]=='\0') return 0;

    int l1 = strlen(haystack);
    int l2 = strlen(needle);

    if(l1<l2) return -1; //长度不足，直接-1.
    //从 字符串haystack第一位开始匹配，直到第 [l1-l2]位还可以检测，在后一位，会导致母传长度不足，可以返回-1.
    
    for(int i=0;i<=l1-l2;i++)
    {
        if(isSame(haystack,needle,i,l2)) return i;
        
    }

    return -1;

}

bool isSame(char *h, char *n,int first,int len) 
// 判断h串从first位置开始 长度为n的长度len之间是否完全一样
{
    for(int i=0;i<len;i++)
    {
        if(h[first+i]!=n[i]) return false;  //一旦一个位置不同，返回false。
    }
    return true;
}

```
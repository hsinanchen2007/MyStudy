### 解题思路
执行用时0ms，超过100%的用户
我并没有用KMP算法，因为我真的不会。一开始只是使用简单的双指针，但是遇到一个全a和只含一个b的特例，就总是超时。按照毛主席具体问题具体分析的原则，我增加了一个判断条件：当模式中元素种类大于主串中元素种类，就一定无法匹配，直接返回-1。

### 代码

```c
int strStr(char * haystack, char * needle){
    int m = 0;
    int n = 0;
    int a[128];
    int b[128];
    int n_count=0,m_count=0;
    char c;
    for(int i=0;i<128;i++)
    {
        a[i] = 0;
        b[i] = 0;
    }
    for(n=0;(c=haystack[n])!='\0';n++)
    {
        if(a[c] == 0){
            n_count++;
            a[c] = 1;
        }
    } 
    for(m=0;(c=needle[m])!='\0';m++)
    {
        if(b[c] == 0){
            m_count++;
            b[c] = 1;
        }
    }
    if(m==0) return 0;
    if(m>n || m_count>n_count) return -1;
    printf("%d %d\n",m_count,n_count);
    int i=0;
    int j=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(haystack[i+j] != needle[j]){
                break;
            }
        }
        if(j == m) return i;
    }
    return -1;
}
```
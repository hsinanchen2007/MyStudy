### 解题思路
将官方解法的ASCII码方式改写为c语言

### 代码

```c
int lengthOfLongestSubstring(char * s){
    int n=strlen(s),max=0,i=0,j=0,h;
    int index[128]={0}; //设置空数组
    for(j=0;j<n;j++)
    {
        h=index[s[j]%127];
        if(i<h)  i=index[s[j]%127]; //调整当前不重复子串的起始点
        if(max<j-i+1)  max=j-i+1; //得出最大的长度
        index[s[j]%127]=j+1;//指出下一个不重复子串的起始点
    }
    return max;
}

```
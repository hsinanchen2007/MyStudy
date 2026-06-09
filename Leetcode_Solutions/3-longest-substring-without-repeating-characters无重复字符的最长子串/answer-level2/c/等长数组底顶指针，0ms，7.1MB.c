```python3 []
def lengthOfLongestSubString(s):
    length = len(s)
    if length <= 1:
        return length
    lst, _max = [], 1
    for i in range(length):
        if s[i] in lst:
            _max = max(_max, len(lst))
            lst = lst[lst.index(s[i])+1:]
        lst.append(s[i])
    return max(_max, len(lst))
```
```c []
int lengthOfLongestSubString(char *s){
    int len = strlen(s);
    if(len<=1) return len;
    int maxlen=1;  // 1
    char *base, *top;
    base=top=(char *)malloc(sizeof(char)*(len+1));
    if(!base) exit(0);
    // travel the s string
    for(int i=0;i<len;i++){
        int isfind=-1, str_len=top-base;  // top-base is the length of stack
        for(int j=0;j<str_len;j++){  // find the char of s[i] in stack
            if(s[i]==base[j]){isfind=j;break;}
        }
        if(isfind!=-1){
            maxlen=str_len>maxlen?str_len:maxlen;
            base+=isfind+1;  // base must assignment
        }
        *top++=s[i];
    }
    return top-base>max?top-base:max;
}
```











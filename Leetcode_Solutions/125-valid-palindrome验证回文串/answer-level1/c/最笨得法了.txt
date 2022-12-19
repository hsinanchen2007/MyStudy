### 这个方法可太笨了哦

### 代码

```c
bool isPalindrome(char * s){
    char tmp[100000];
    int len = strlen(s);
    int k = 0;
    if(s == "")
        return true;
    for(int i = 0;i<len;i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }
    for(int j=0;j<len;j++){
        if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))
            tmp[k++] = s[j];
    }
    int m = 0;
    int n = k-1;
    while(m <= (k-1)/2 && n>0){
        if(tmp[m] == tmp [n]){
            m++;
            n--;
        }else
            return false;
    }

    return true;
}
```
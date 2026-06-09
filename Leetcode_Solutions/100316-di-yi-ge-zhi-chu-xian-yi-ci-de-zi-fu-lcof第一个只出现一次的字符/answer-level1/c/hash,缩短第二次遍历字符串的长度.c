第一次遍历时遇到重复2次以上的字符时，删去该字符并前移后面的字符，这样第二次遍历时字符串每个字符都只出现一次，再从中找到第一个没重复的字符即可。

```
char firstUniqChar(char* s){
    if(s == ""){
        return ' ';
    }
    char ch;
    int i = 0,n = 0;
    int arr[128] = {0};

    while((ch = s[i]) != '\0'){
        arr[ch]--;
        s[i - n] = s[i];
        if(arr[ch] <= -2){
            n++;
        }
        i++;
    }

    s[i - n] = '\0';
    i = 0;

    while((ch = s[i]) != '\0'){
        if(arr[ch] == -1){
            return ch;
        }
        i++;
    }
    return ' ';
}
```

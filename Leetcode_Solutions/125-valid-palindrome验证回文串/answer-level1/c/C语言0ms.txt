### 解题思路

申请一个新的字符串，大小和给定的一样大，然后将之前的字符串里的数字和字母给新的字符串

然后依次比较前面和后面的字符

### 代码

```c
bool isPalindrome(char * s){

    int str_len = strlen(s);
    char *new_s = (char *)malloc( sizeof(char) * str_len);
    int j = 0;

    for (int i =0 ; i < str_len; i++){
        if ( s[i] >= 'A' && s[i] <= 'Z'){
            new_s[j++] =  tolower(s[i]);
        } else if ( s[i] >= 'a' && s[i] <= 'z'){
            new_s[j++] = s[i];
        } else if (s[i] >= '0' && s[i] <= '9'){
            new_s[j++] = s[i];
        } else{
            continue;
        }
    }
    
    for ( int i = 0; i < (j/2); i ++){
        if (new_s[i] != new_s[j-i-1]){
            return false;
        }
    }
    return true;



}
```
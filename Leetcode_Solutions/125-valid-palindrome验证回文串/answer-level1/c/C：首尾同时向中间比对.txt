思路：
首尾同时向中间比对，不是字母数字就跳过，
结束循环的条件是首尾的标记相遇
```
bool isPalindrome(char * s){
    int left = 0;
    int right = strlen(s) - 1;
    while(left < right){
        if(!isalnum(s[left])){
            left++;
            continue;
        }
        if(!isalnum(s[right])){
            right--;
            continue;
        }
        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
```

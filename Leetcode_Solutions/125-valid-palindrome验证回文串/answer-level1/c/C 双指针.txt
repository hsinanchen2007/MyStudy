### 解题思路
首先遍历一遍字符串，把大写字母转成小写字母,O(n）;
start 指向字符串头， tail 指向末尾；
跳过不是字母和字符串的字符，比较头尾指向的有效字符是否相等，若不相等，返回 false;

### 代码

```c
/*
执行用时 :8 ms, 在所有 C 提交中击败了50.44% 的用户
内存消耗 :7.7 MB, 在所有 C 提交中击败了24.40%的用户
*/
bool isPalindrome(char * s){
    int len = strlen(s);
    if(len == 0|| len == 1) return true;
    int start = 0;
    int tail = len-1;
    for(int i = 0;i<len;i++){
        if(isupper(s[i])){
            s[i] += 32;
        }
    }
    for(;start < tail ;start++,tail--){
        while((start<tail)&&(!islower(s[start]))&&(!isdigit(s[start]))){
            start++;
        }
        if(start == tail) return true;//中间一直是其他字符
        while((!islower(s[tail]))&&(!isdigit(s[tail])) ){
            tail--;
        }
        if(s[start] != s[tail]){
            return false;
        }
    }
    return true;
}
```
### 解题思路
用一个数组记录每个字母出现的次数,看每个字母出现次数是2的几倍result就加几个2，最后判断字母中有没有出现次数是奇次的，如果有result再加1，出现奇次的字母可以取出来一个当做回文串的中心。

### 代码

```c
int longestPalindrome(char * s){
    int result=0;
    int count[52] = {0,};
    for(int i=0;s[i]!='\0';i++){
        if(s[i] <= 'Z'){
            count[s[i]-'A'+26]++;
        }else{
            count[s[i]-'a']++;
        }
    }
    for(int i=0;i<52;i++){
        result += count[i]/2*2;
    }
    for(int i=0;i<52;i++){
        if(count[i]&1){
            result++;
            break;
        }
    }
    return result;
 
}
```
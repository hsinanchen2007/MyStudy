**检查一半数量的字符就可以了
遇到不是'a'的就赋值为'a'，否则将最后一个字符赋值为'b'。**
```
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.size();
        if(len < 2){
            return "";
        }
        
        for(int i = 0; i < len / 2; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[len - 1] = 'b';
        return palindrome;
    }
};

```
![2.png](https://pic.leetcode-cn.com/9c8b3d06849bb01bacdebe8288d4bebf1d156dc7a534658f8d503258b4cad100-2.png)

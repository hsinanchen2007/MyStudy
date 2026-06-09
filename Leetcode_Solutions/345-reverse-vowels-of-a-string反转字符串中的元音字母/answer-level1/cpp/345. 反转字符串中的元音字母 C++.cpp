### 解题思路
1.双指针前后遍历，检索到元音字符在做互换。

### 代码

```cpp
class Solution {
public:
    bool isVowel(char s){
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U'){
            return true;
        }
        else{
            return false;
        }
    }


    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        char temp;
        
        while(left < right){
            while(left < right && !isVowel(s[left])){
                left++;
            }
            while(left < right && !isVowel(s[right])){
                right--;
            }
            temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--; 
        }
        return s;
    }
};
```
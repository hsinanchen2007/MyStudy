### 解题思路
双指针

### 代码

```cpp
class Solution {
public:
    bool isVowels(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        if(s.empty())return "";
        int left=0;
        int right=s.size()-1;

        while(left<right){
            if(!isVowels(s[left])){
                left++;
            }
            if(!isVowels(s[right])){
                right--;
            }
            if(isVowels(s[left])&&isVowels(s[right])){
               char tmp=s[left];
               s[left]=s[right];
               s[right]=tmp;
               right--;
               left++;
            }
        }
        return s;
    }
};
```
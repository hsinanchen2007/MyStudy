### 解题思路
此处撰写解题思路

### 代码

```cpp
bool IsNumber(char c){
    if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return true;
    }
    return false;
}

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;

        int start = 0;
        int end = s.size() - 1;

        while(start < end){
            while(start != end){
                if(IsNumber(s[start])){
                    if((s[start] >= 'A' && s[start] <= 'Z')){
                        s[start] += 32;
                    }
                    break;
                }
                    
                ++start;
            }

            while(start != end){
                if(IsNumber(s[end])){
                    if((s[end] >= 'A' && s[end] <= 'Z')){
                        s[end] += 32;
                    }
                    break;
                }
                
                --end;
            }

            if(s[start] == s[end]){
                ++start;
                --end;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
```
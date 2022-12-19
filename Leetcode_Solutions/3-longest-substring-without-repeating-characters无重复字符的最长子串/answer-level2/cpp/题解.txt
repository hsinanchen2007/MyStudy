### 解题思路
见代码注释处

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0;
        for(int i=0;i<s.length();i++){
            int j;
            for(j=i+1;j<s.length();j++){
                int flag=0;
                for(int k=i;k<j;k++){
                    if(s[j]==s[k]){
                        flag=1;
                        break;
                    }
                }
                if(flag){
                    if(j-i>max){
                        max=j-i;
                    }
                    break;//字符串出现重复就要退出
                }
            }
            if(j==s.length()){
                if(j-i>max){
                        max=j-i;
                    }
            }
        }
        return max;
    }
};
```
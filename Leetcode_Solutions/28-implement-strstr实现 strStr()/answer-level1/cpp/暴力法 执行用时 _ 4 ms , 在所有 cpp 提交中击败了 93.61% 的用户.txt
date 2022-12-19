### 解题思路
此处撰写解题思路
用substr后，感觉只有O(N)的复杂度。。哈哈
### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()){
            return -1;
        }
        if(haystack=="" && needle==""){
            return 0;
        }
        for(int i=0;i<haystack.size()-needle.size()+1;i++){
            if(haystack.substr(i,needle.size())==needle){
                return i;
            }
        }
        return -1;
    }
};
```
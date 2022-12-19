### 解题思路
1.创建辅助数组
2. 每次mismatch检查尾部下一个字符决定偏移量。

### 代码

```cpp
class Solution {
public:
   class Solution {
public:
    // sunday
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return 0;
        }
        if(haystack.empty()){
            return -1;
        }

        // get assistance array
        int len = needle.length();
        vector<int> sunday(256, len+1);

        for(int i=0; i<len; i++ ){
            sunday[needle[i]] = len-i; 
        }

        int i=0;
        int j=0;
        while(i<haystack.length()){
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j == needle.length()){
                    return i-j;
                }
            }else{
                int end = i-j+len;
                if(end>=haystack.length()){
                    return -1;
                }
                i = i-j+sunday[haystack[end]];
                j = 0;
            }
        }
        return -1;

    }
};
```
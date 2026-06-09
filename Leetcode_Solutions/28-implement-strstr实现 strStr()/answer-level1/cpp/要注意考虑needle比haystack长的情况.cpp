### 解题思路
详细见代码，太简单了，没啥说的

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        for(int i = 0; i < len1 - len2 + 1; ++i){
            bool flag = true;
            for(int j = 0; j < len2; ++j){
                if(haystack[i+j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return -1;
    }

};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 92.05% 的用户 
内存消耗 : 6.7 MB , 在所有 C++ 提交中击败了 100.00% 的用户
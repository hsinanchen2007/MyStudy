### 解题思路
实现简单的递归

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string before = countAndSay(n-1);
        string ret;
        int i=0;
        while(i<before.length()){
            int j=0;
            while(before[i] == before[i+j]) j++;
            ret += to_string(j) + before[i];
            i+=j;
        }
        return ret;
    }
};
```
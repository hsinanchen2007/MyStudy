### 解题思路
双端队列：一边插入一边弹出

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {

        int i = 0;
        while(i<n){
            s.push_back(s.front());
            s.erase(s.begin());
            i++;
        }

        return s;
    }
};
```
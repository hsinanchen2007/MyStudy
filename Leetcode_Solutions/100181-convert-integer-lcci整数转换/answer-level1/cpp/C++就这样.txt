### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int convertInteger(int A, int B) {
        int cnt = 0;
        for (int i = 31; i >= 0; i --)
            if ((A >> i & 1) ^ (B >> i & 1)) cnt ++;
        return cnt;
    }
};
```
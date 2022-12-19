### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int convertInteger(int A, int B) {
        int res = A ^ B;

        int count = 0;
        for(int i=0;i<32;i++)
        {
            if (res&1 == 1)
                count++;
            res >>= 1;
        }
        
        return count;
    }
};
```
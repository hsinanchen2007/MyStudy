### 解题思路
首先前提是一定存在半数通过。那么可以认为，及时所有非majority数加在一起，也没有majority出现的次数多。所以出现一次不同就减一，出现一次相同就加一，最后剩下的也一定是majority。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (auto num : nums) {
            if (num == candidate) {
                count++;
            } else {
                count--;
                if (count <= 0) {
                    count = 1;
                    candidate = num;
                }
            }
        }
        return candidate;
    }
}; 
```
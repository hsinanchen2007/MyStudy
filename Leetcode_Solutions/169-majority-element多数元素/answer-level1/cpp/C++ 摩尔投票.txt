### 解题思路
摩尔投票法，核心思想就是不同的就相消。相同的就相加。最后看剩下是什么。
维护一个major，count。
先初始化count = 0；
遍历数组
如果count ==0，marjor = n
如果count != 0, 如果major==n，则count++，否则count--；

最后看看major是什么

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, count = 0;
        for (auto n : nums) {
            if (count == 0) {
                major = n;
                count = 1;
                continue;
            } 
            if (major == n) {
                count++;
            }
            if (major != n) {
                count--;
            }
        }
        return major;
    }
};
```
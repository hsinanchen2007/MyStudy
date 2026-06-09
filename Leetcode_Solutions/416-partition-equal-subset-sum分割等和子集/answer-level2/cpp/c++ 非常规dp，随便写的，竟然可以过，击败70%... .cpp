### 解题思路
抱着试一试的心态，写了一个我一下想到的也是我认为非常暴力的做法。。竟然过了，震惊。。

仔细思考了一下其实和dp可能还是同源的...主要是减少了之前的和重复的情况

 
![image.png](https://pic.leetcode-cn.com/5289f8da4368aab1dc895dbacf3236f4e6de0e336a1cf9d5af1737409d8a8a07-image.png)


[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
最近沉迷刷题，真诚欢迎大家star和follow 最近也在学习和实现lua，欢迎交流

### 代码

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        if (sum %2 != 0) return false;
        sum = sum / 2;
        unordered_map<int, int> m;

        for (auto num: nums) {
            if (num == sum) return true;
            for (auto p: m) {
                if (num+p.first == sum) return true;
                m[num+p.first] = 1;
            }
            m[num] = 1;
        }

        return false;
    }
};
```
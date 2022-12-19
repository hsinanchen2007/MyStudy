### 解题思路
和[14- I. 剪绳子 C++ 动态规划 双100%](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/14-i-jian-sheng-zi-c-dong-tai-gui-hua-shuang-100-b/)思路相同，这里设计了iPow函数防止溢出[参考](https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/shuang-bai-_yi-ge-fang-zhi-yi-chu-han-shu-ji-ke-ji/)

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;    // 如果绳子长度为2,只能分成1*1
        if(n == 3) return 2;    // 如果绳子长度为3,只能分成1*2
        // if(n == 4) return 4;

        int numsOf3 = n / 3;
        int res = 0;

        if(n % 3 == 1){
            // 说明最后会剩下一个4,这时要把4拆分成2*2
            return (iPow(3, (numsOf3 - 1)) * 4) % 1000000007;
        }
        else if(n % 3 == 2){
            // 说明最后会剩下一个2
            return (iPow(3, numsOf3) * 2) % 1000000007;
        }
        return (iPow(3, numsOf3)) % 1000000007;
    }
    long long int iPow(int n, int e){
        // 因为pow会溢出，这里设计一个iPow
        // res来存放结果，为了保证res不溢出这里设置为long long
        long long int res = 1;
        for(int i = 0; i < e; ++i){
            res *= n;
            if(res * n > 1000000007){
                // 对结果取模
                res %= 1000000007;
            }
        }
        return res;
    }
};
```
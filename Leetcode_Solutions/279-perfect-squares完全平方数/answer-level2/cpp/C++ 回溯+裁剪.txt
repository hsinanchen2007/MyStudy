1. 先把不大于n的完全平方数都算出来，再逆序一下，大的数在前面优先选择
2. 回溯所有解法，每一步减去用掉的完全平方数，并累计数目
3. 当剩余为0时，记录答案，保留最小的方案


![image.png](https://pic.leetcode-cn.com/c8078ea84f6614f64fdfec1e4e1686fc133c6c248299828bf6325de027005dbf-image.png)

```
class Solution {
public:
    int minCnt{INT_MAX};
    
    void backtrace(vector<int>& squareNum, int remain, int cnt) {
        if (cnt > minCnt) // 裁剪: 代价已经比曾经算出来的方案大，裁剪掉
            return ;
        if (remain == 0) {
            minCnt = min(cnt, minCnt);
            return ;
        }
        for (int sqn : squareNum) {
            if (remain >= sqn) {
                int cps = remain / sqn;  // 较大的数，尽可能多用
                backtrace(squareNum, remain % sqn, cnt + cps);
            }
        }
    }
    
    int numSquares(int n) {
        vector<int> squareNum;
        int i = 1;
        while (i * i <= n) {
            squareNum.push_back(i * i);
            ++i;
        }
        reverse(squareNum.begin(), squareNum.end());  // 反转一下，大的数放前面，优先选择。
        
        backtrace(squareNum, n, 0);
        return minCnt;
    }
};
```

```
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, 0);
        res[0] = 1;
        int ptr2 = 0;
        int ptr3 = 0;
        int ptr5 = 0;
        for(int i = 1; i < n; ++i)
        {
            // 选取最小的candidate加入丑数队列
            res[i] = min(res[ptr2]*2, min(res[ptr3]*3, res[ptr5]*5));
            // 检查最小的值是哪一个指针产生的，把对应指针后移一位（原位置的值已用，把下一个最小值作为下一轮candidate）
            // 原理类似滑动窗口
            // 注意，最小值可能同时存在于多个指针中，把结果等于最小值的指针全部后移，以避免下一轮加入重复的元素
            if(res[i] == res[ptr2]*2) ptr2++;
            if(res[i] == res[ptr3]*3) ptr3++;
            if(res[i] == res[ptr5]*5) ptr5++;
        }
        return res[n-1];
    }
};
```

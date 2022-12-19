### 解题思路
1.暴力：遍历所有数字
2.小顶堆：采用优先级队列，让最小的值在堆顶，每次取最小的值弹出分别乘以 2 3 5，然后去重，放入dp
3.三队列方法：比较经典，可以参考别人的解题思路

方法1：暴力
```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        for (long long a=1;a<=INT_MAX;a=a*2)
            for (long long b=a;b<=INT_MAX;b=b*3)
                for (long long c=b;c<=INT_MAX;c=c*5)
                    v.push_back(c);
        sort(v.begin(),v.end());
        return v.at(n-1);
    }
};
```


方法2：小顶堆
### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, deque<long>, greater<long>> minHeap;
        set<long> numSet;
        vector<long> dp(n + 1, 0);

        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int factors[3] = { 2, 3, 5 };
            for (int t = 0; t < 3; t++) {
                long value = dp[i - 1] * factors[t];
                if (!numSet.count(value)) {
                    minHeap.push(value);
                    numSet.insert(value);
                }
            }

            dp[i] = minHeap.top();
            minHeap.pop();
        }
        return dp[n];
    }
};
```

//方法3：三队列的牛逼方法
```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        
        static vector<int>nums={1};
        static  int i2=0;
        static  int i3=0;
        static  int i5=0;
        
        while(nums.size()<n)
        {
            const int next2=nums[i2]*2;
            const int next3=nums[i3]*3;
            const int next5=nums[i5]*5;
            
            int next=min(next2,min(next3,next5));
            if(next==next2) ++i2;
            if(next==next3) ++i3;
            if(next==next5) ++i5;
            nums.push_back(next);
        }
        
        return nums[n-1];
        
    }
};
```

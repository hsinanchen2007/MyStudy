1 由于是环形数组，可以将数组扩展至原来的两倍，相当于复制一遍数组元素，求长度最大为n的子数组。
2 求出所有的前缀和，要使sum[i]-sum[j]最大，对于每一个i，只需要sum[j]最小
3 求范围内的最小值，可以用单调递增队列来实现，队首元素即为目前的最小值。（需要提前判断队首元素和当前元素下标是否大于n），更新当前的答案。
4 入队时，比较队尾元素和当前元素的值，如果队尾元素值大于等于当前元素，则队尾元素出队，直到当前元素大于队尾元素时，当前元素入队。
```
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        for(int i = 0;i<n;i++) A.push_back(A[i]);
        vector<int> sum(n*2+1);
        for(int i = 1;i<=n*2;i++) sum[i] = sum[i-1] + A[i-1];

        deque<int> q;
        q.push_back(0);
        int res = INT_MIN;
        for(int i = 1;i<=n*2;i++)
        {
            if(q.size() && i - q.front()>n) q.pop_front();
            if(q.size()) res = max(res,sum[i]-sum[q.front()]);
            while(q.size() && sum[q.back()] >= sum[i]) q.pop_back();
            q.push_back(i);
        }

        return res;
    }
};
```

1. 若令sum[i]是累加到第i个元素的累加和，那么子数组A(i,j]的和为sum[j] - sum[i]
2. 利用单调递增栈保存累加和。
3. 当遍历到A的元素i，在单调递增栈中利用二分查找距离最近的符合要求的累加和，如果找到刷新答案。
4. 时间复杂度o(nlg(单调栈平均长度))，空间复杂度o(n),主要是存单调栈的空间消耗。
```
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        if(A.size() == 0)
            return -1;
        int ans = A.size() + 1;
        vector<vector<int>> s; //s中的每一个元素都是一个长度为2的数组{到地址为止的count值，地址}
        vector<int> leftBound = {0,-1};
        s.push_back(leftBound);
        int count = 0;
        for(int i = 0;i<A.size();i++)
        {
            if(A[i] >= K)
                return 1;
            //维护到i为止的累加和count
            count += A[i];
            //更新ans,需要用二分查找降低时间复杂度
            int left = 0;
            int right = s.size() - 1;
            while(left < right)
            {
                int mid = (left + right) / 2 + 1;
                if(count - s[mid][0] < K)
                    right = mid - 1;
                else
                    left = mid;
            }
            if(count - s[left][0] >= K)
                ans = min(ans,i-s[left][1]);
            //维护单调递增栈s
            while(s.size() > 0 && s.back()[0] >= count)
                s.pop_back();
            vector<int> temp = {count,i};
            s.push_back(temp);
        }
        return ans <= A.size() ? ans : -1;//检查是否存在满足题意的子数组
    }
};
```
- 拓展：如果题目改成"和至少为0至多为K的最短子数组",如何求解
我一开始把题目看错了看成这个了...然后用桶的方法在做(可以做到线性时间复杂度)。
不知道leetcode上有没有类似的题，有大佬看到了告知一声。
**题目分析**
对于输入 A = $[A_i]$, L, R.
对于某个满足 $L\leq A_i \leq R$ 的 $A_i$  , 如果知道最小的 $l$ 使得 $\forall j\in [l+1,i], L\leq A_j\leq A_i$
以及最大的 $r$ 使得 $\forall j \in [i,r-1], L\leq A_j \leq A_i$
那么有满足最大值为 $A_i$ 且 $L\leq A_i \leq R$ 的子数组的个数为 $(i-l)*(r-i)$

那么对于 $A[i]$ 怎么找对应的 $l$ 和 $r$ ?
暴力的方法可以分别遍历 range(i-1,-1,-1) 以及 range(i+1,n)，分别找第一个 $l$ 和 $r$ 使得 $A_l>A_i$ 和 $A_r>A_i$
显然每个 $A[i]$ 要花费 O(n) 的时间求 $l$ 和 $r$ , 总体的时间复杂度就是 O($n^2$) 

一种优化的方法就是把每个 i 对应的 $l$ 和 $r$ 用 O(n) 的时间提前求出来，也就是单调栈

**单调栈**
我们用 $l[i]$ 表示 $i$ 对应的 $l$，$r[i]$ 表示 $i$ 对应的 $r$。
首先介绍求 $l$ 的方法 。
在这里我们使用单调减的栈来存储数组的下标，当一个新的下标 $i$ 到来， 如果栈顶元素 stack.top() (记为 $j$) 不满足 $A[i]< A[j]$ ，就不停 pop 出栈顶元素，直到满足条件为止。
这样的好处是当停止出栈，要么 A[i] 是目前的最大值 (栈为空)，要么 stack.top() 即为要求的 $l$ ，即 $l[i]$ = stack.top() 或 -1
求 $r$ 的方法几乎完全一致，只需要遍历的顺序从 range(n) 变为 range(n-1,-1,-1),以及为了**去重** 把不满足 $A[i]< A[j]$ 改为 $A[i]\leq A[j]$ 即可。

**Python3 和 C++ 代码**
```
class Solution:
    def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
        stk = []
        l = [-1]*(n:=len(A))
        for i in range(n):
            while stk and A[i]>=A[stk[-1]]:
                stk.pop()
            if stk:
                l[i] = stk[-1]
            stk.append(i)
        r = [n] * n
        stk = []
        for i in range(n-1,-1,-1):
            while stk and A[i]>A[stk[-1]]:
                stk.pop()
            if stk:
                r[i] = stk[-1]
            stk.append(i)
        ans = 0
        for i in range(n):
            if A[i]<L or A[i]>R:
                continue
            ans += (i - l[i])*(r[i] - i)
        return ans
```

```
class Solution {
public:
    int l[50005],r[50005];
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        stack<int>st;
        int n=A.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && A[i]>=A[st.top()])st.pop();
            l[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1;~i;i--){
            while(!st.empty() && A[i]>A[st.top()])st.pop();
            r[i] = st.empty()?n:st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            if(L<=A[i] && R>=A[i])
                ans += (i - l[i])*(r[i] - i);
        return ans;
    }
};
```




 
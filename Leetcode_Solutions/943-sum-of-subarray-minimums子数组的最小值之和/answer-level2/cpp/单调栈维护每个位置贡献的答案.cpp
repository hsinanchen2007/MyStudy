$l[i]$是$A[i]$左边第一个小于$A[i]$的下标
$r[i]$是$A[i$]右边第一个小于$A[i]$的下标
那么$A[i]$位置贡献的答案就是$(i-l[i])*(r[i]-i)*A[i]$
注意可能有重复元素所以一个小于等于,一个小于

```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<int>s;
        int n = A.size(),l[n],r[n],result=0,mod=1000000000+7;
        for(int i=0;i<n;++i){
            while(!s.empty() && A[i] <= A[s.top()])s.pop();
            if(s.empty())l[i]=-1;
            else l[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;--i){
            while(!s.empty() && A[i] < A[s.top()])s.pop();
            if(s.empty())r[i]=n;
            else r[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;++i){
            result = (result + (i-l[i]) * (r[i]-i) * A[i]) % mod; 
        }
        return result;
    }
};
```
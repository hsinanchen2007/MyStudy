### 解题思路
求连续的非空子数组的个数，满足它的元素的和为S

先求出前缀和sum[i]=A[0]+A[1]+...+A[i-1] , sum[0]=0
以i为区间右端点，j为区间左端点
对满足sum[i]-sum[j]=S  (A[j]+A[j+1]+...+A[i-1]=S)   的j的个数进行计数累加
其中i:[1,A.size()],j:[0,i-1]

对j的个数进行计数累加需要两个循环，时间复杂度为O(n^2)
```cpp
int count=0;
for(int i=1;i<n+1;i++)
    for(int j=0;j<i;j++)
        if(sum[i]-sum[j]==S)
            count++;
```

注意到sum[i]一定是非严格单调上升的，而且是连续的，相邻两个位置的值最多相差1
若增加一个数组f[],记录j的个数，可降低时间复杂度为O(n)
sum[j]=sum[i]-S 
f[i]为sum[j]=i的j的个数(sum[]中等于i的有多少个)，即：
f[sum[i]-S]为sum[j]=sum[i]-S的j的个数(sum[]中值为sum[i]-S的个数)
f[sum[i]]为sum[]中值为sum[i]的个数

示例：
A   [1,0,1,0,1]
sum [0,1,1,2,2,3]
f   [1,2,2,1,0,0]



### 代码

```cpp
class Solution {
public:
    //前缀和
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n=A.size();
        if(n==0) return 0;
        int sum[n+1]={0},f[n+1]={0};
        f[0]=1;
        for(int i=1;i<n+1;i++)
           sum[i]=sum[i-1]+A[i-1];
        int count=0;
        for(int i=1;i<n+1;i++){
            if(sum[i]>=S)
               count+=f[sum[i]-S];
            f[sum[i]]++;
        }
            
        return count;
    }
};
```
暴力枚举的做法就不提了，下面谈谈如何优化
以下`[i:j]`表示`i`到`j`( 不包括`j`)
我们可以将原问题抽象如下：
找到所有满足`0<=i<=j<n`,使得`sum(nums[i:j+1])==target`.
`sum(nums[i:j+1])`这个式子利用前缀和可以写成`pre[j]-pre[i]`,其中`pre[j]`表示前`j`个数的和即`sum(nums[0:j])`.
因此，可以枚举`j`的位置,计算出`pre[j]`之后，再从`[0:j]`中寻找`i`,使得`pre[i]=pre[j]-target`,这样子根据`sum(nums[i:j+1]) = pre[j]-pre[i] = pre[j] - (pre[j] - target) = target`,知道`[i,j]`是满足条件的一组下标.

我们可以不用定义`pre`数组，只用一个变量`sum`来记录每次的`pre[j]`,这是从`pre`的计算方式和我们枚举`j`的方向
得到.
最终代码如下
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        //加入哨兵
        mp[0]=1;
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            cnt+=mp[sum-k];
            mp[sum]+=1;
        }
        return cnt;
    }
};
```
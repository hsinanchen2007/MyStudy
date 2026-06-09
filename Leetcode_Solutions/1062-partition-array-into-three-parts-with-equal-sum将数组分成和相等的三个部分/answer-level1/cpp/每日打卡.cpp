### 解题思路
可以在O(n)的时间复杂度完成，双重循环遍历会超时，因为当第一段和不为sum/3的情况是肯定不能得到true的，所以可以线性找到第一个分割点，再线性找第二个。为什么是第一个分割点，这个是一种贪心的思想，并可以得到证明，具体证明步骤可以参考官方题解，很简单。

### 代码

```cpp
class Solution {
public:
//具体思路可以看官方题解，小小利用了贪心思想
    bool canThreePartsEqualSum(vector<int>& A) {
        int n=A.size();
        int i,target;
        vector<int> dl(n,0); dl[0]=A[0];
        for(i=1;i<n;i++) dl[i]=dl[i-1]+A[i];
        if(dl[n-1]%3!=0) return false;
        else target=dl[n-1]/3;
        for(i=0;i<n-2;i++){
            if(dl[i]==target) break;
        }
        for(i++;i<n-1;i++){
            if(dl[i]==target*2) return true;
        }
        return false;
    }
};
```
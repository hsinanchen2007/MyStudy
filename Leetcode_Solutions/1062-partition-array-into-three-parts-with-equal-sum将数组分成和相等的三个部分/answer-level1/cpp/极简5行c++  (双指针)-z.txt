### 解题思路
双指针法debug了好多次，难受，sum为0的情况太难受了

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0,sum1=A[0],sum2=A[A.size()-1],left=1,right=A.size()-2;
        
        for(int n:A)    sum+=n;                 //计算数组总和
        while(left<right && sum1!=sum/3)        sum1+=A[left++];
        while(right>0 && sum2!=sum/3)           sum2+=A[right--];

         return sum%3==0 & left<=right;;
    }
};
```
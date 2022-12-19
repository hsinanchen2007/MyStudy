### 解题思路
思路：
1.先排序
2.设定left和right边界，right边界为数组最右边
3.A[left]+A[right]和K比大小，如果A[left]+A[right]<K则说明A[left]+A[right]的和符合条件，并且还需要不断取较大值作为结果，并更新左边界，如果A[left]+A[right]>=K,条件不符合则只移动右边界，直到条件符合
4.最后如果不存在合适的值则返回-1

### 代码

```cpp
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int res=INT_MIN;
        int s=A.size();
        int left=0;
        int right=s-1;
        sort(A.begin(),A.end());
        while(left<right){
            if(A[left]+A[right]<K){
                res=max(res,A[left]+A[right]);
                left++;
            }else{
                right--;
            }
        }
        if(res==INT_MIN) res=-1;
        return res;
    }
};
```
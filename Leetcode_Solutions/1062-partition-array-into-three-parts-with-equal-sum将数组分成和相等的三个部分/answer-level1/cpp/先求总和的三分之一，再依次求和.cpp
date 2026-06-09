### 解题思路
先求出数组总和的三分之一x
sum函数是求数组中从begin到end之和
在主函数中，先求i，使得从0到i的和为x
再求j，使得从i到j的和为x
最后求j到数组最后一位的和，检查其是否等于x

### 代码

```cpp
class Solution {
public:
    //getSum of the range of A：[begin,end)
    int sum(vector<int>& A,int begin,int end){
        int ans = 0;
        if(begin >= 0 && end <= A.size())
            for(int i = begin;i < end;i ++){
                ans += A[i];
            }
        return ans;
    }

    bool canThreePartsEqualSum(vector<int>& A) {
        int x,i,j;
        x = sum(A,0,A.size()) / 3;

        for(i = 1;i <= A.size();i ++){
            if(sum(A,0,i) == x)
                break;
        }

       if(i == A.size())
            return false;

        for(j = i;j < A.size();j ++){
            if(sum(A,i,j+1) == x)
                break;
        }

        if(j == A.size()-1)
            return false;

        if(sum(A,j+1,A.size()) == x)
            return true;
        else
            return false;
    }
};
```
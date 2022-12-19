区间大于等于L小于等于R的子数组个数=区间小于等于R的子数组个数-区间小于L的子数组个数；
按照这个思想，遍历两边数组，算出来一减就是答案了。

```C++ []
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int t1 = 0,t2 = 0;
        int n = A.size();
        for(int i=0,j=0;i<n;){
            if(A[i]<=R){
                ++i;
                t1 += i-j;
            }
            else {
                ++i;
                j=i;
            }
        }
        for(int i=0,j=0;i<n;){
            if(A[i]<L){
                ++i;
                t2 += i-j;
            }
            else {
                ++i;
                j=i;
            }
        }
        return t1-t2;
    }
};
```




![image.png](https://pic.leetcode-cn.com/a922d9b3e8588a5bf9b95176af93b44e51d3ae54cf8829cddc49d8146e82347b-image.png)


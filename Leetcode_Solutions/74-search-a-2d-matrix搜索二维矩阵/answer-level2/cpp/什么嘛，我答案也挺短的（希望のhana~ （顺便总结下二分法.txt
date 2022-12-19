### 解题思路

就二分，无脑二分。

对于升序队列nums，一般二分查找会有左中点`mid = (l+r)/2 `和右中点`mid = (l+r+1)/2 `

如果是查找一个具体的值，那么两者都可以用，需要注意的地方是在二分的时候

如果选取的左中点,因为mid是靠近左边的，有可能是l本身，故为了避免死循环，应该l逼近r：
```
l = mid+1;
r = mid;
```
反之如果选取的右中点,因为mid是靠近右边的，有可能是r本身，故为了避免死循环，应该r逼近l：
```
l = mid;
r = mid-1;
```

如果查找不是一个具体的值，而是小于等于目标的值,比如这个问题中第一列的二分法，因为答案是靠左侧的，所以用r逼近l，选用右中点；反之选用左中点。



### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int u =0,d=matrix.size()-1;
        if(d<0) return false;
        while(u<d){
            int mid = (u+d+1)/2;
            if(matrix[mid][0]>target)
                d = mid-1;
            else
                u = mid;
        }
        int l = 0,r = matrix[0].size()-1;
        if(r<0) return false;
        while(l<r){
            int mid = (l+r)/2;
            if(matrix[u][mid]>=target)
                r = mid;
            else
                l = mid+1;
        }
        return matrix[u][l]==target;
    }
};
```
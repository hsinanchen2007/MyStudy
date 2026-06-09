### 解题思路
先二分查找找到0的下标。
然后双指针，其实就是合并两个有序链表。
![image.png](https://pic.leetcode-cn.com/dbf256ba2dc3ee91db246ab7318399fe8711589a3d8a307c5828f5af6ce130d9-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l = A.size();
        vector<int> ret;
        if(l==0)
            return ret;
        if(l == 1)
        {
            ret.push_back(A[0]*A[0]);
            return ret;
        }
        int count = std::lower_bound(A.begin(), A.end(), 0)-A.begin();
        int left = count-1;
        int right = count;
        while(left>=0&&right<l)
        {
            int leftv = A[left]*A[left];
            int rightv = A[right]*A[right];
            if(leftv < rightv)
            {
                ret.push_back(leftv);
                left--;
            }else{
                ret.push_back(rightv);
                right++;
            }
        }
        while(left>=0)
        {
            ret.push_back(A[left]*A[left]);
            left--;
        }
        while(right<l)
        {
            ret.push_back(A[right]*A[right]);
            right++;
        }
        return ret;
    }
};
```
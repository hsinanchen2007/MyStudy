实实在在的超过100%
```c++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size();
        for(int i=(l+r)/2;l<=r;i=(l+r)/2){
            if(i>0&&A[i-1]>A[i])
                r = i-1;
            else if(i+1<A.size()&&A[i+1]>A[i])
                l = i+1;
            else
                return i;
        }
        return -1;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8c9d144f502b523ed2e30dff1f951b2c8b190fc09efd103eddd5eb8c83aa1d78-image.png)

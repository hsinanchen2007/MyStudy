

一般二分查找
--------------
![image.png](https://pic.leetcode-cn.com/42521b5b612274a0a17b0c550581079a1b45d452eb947a94c2e096df9770bd83-image.png)

```cpp
bool isBadVersion(int version);

class Solution {
public:
    //二分法：
    //目标以左：isBadVersion(int mid)==false;
    //目标以右：isBadVersion(int mid)==true;
    //最终mid low high 指向目标 ，目标为false，所以high继续向前移动，而low所指即为目标
    int firstBadVersion(int n) {
        int low=1,high=n,mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(!isBadVersion(mid)){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};
```
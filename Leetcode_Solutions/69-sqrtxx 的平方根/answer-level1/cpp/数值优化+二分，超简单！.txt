### 解题思路
数值优化+二分。超简单
![image.png](https://pic.leetcode-cn.com/191feb2f4a5233f8c11c0f29f9722f2dfaff1dc885b6ec4ddc71ae952adaea37-image.png)

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        else if (x<4) return 1;
        else if (x<9) return 2;
        else if (x<16) return 3;
        int left = 1,right = x/4;
        while(left<=right){
            long long mid = (right-left)/2+left;
            //cout << mid<<" ";
            if ((mid+1)*(mid+1)<=x) left=mid+1;
            else if (mid*mid>x) right = mid-1;
            else return mid;
        }
        return 0;
    }
};
```
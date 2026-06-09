### 解题思路
此处撰写解题思路
二分法，保证left为正确，保证right为错误，当两者相邻时返回right。
### 代码

```cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left=1,right=n;
        if(isBadVersion(1))
            return 1;
            else
            {
                 while(left<right-1)
        {
            int mid=(left+right)/2;
            if(isBadVersion(mid))
                right=mid;
            else
                left=mid;
              
            }
        return right;
        }
    }  
      
    
};
```
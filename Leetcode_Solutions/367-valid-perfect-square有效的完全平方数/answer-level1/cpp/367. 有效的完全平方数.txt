### 解题思路
二分法

### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=0;
        if(num==0)return true;
        int r=46340;
        int sq=r*r;
        if(num==sq)return true;
        if(num>sq)return false;

        while(l<r)
        {
            int mid=(l+r)>>1;
            sq=mid*mid;
            if(num>sq)
            {
                l=mid+1;
            }
            else if(num<sq)
            {
                r=mid;
            }
            else
            {
                return true;
            }
        }
        sq=l*l;
        if(num==sq)return true;
        else return false;

    }
};
```
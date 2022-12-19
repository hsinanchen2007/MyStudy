### 解题思路
二分法，获得中值的平方和x相比
双100

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int left=0,right=x;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(pow(mid,2)>x)
              right=mid-1;
            else if(pow(mid,2)<x)
              left=mid+1;
            else if(pow(mid,2)==x)
               return mid; 
        }
        return left-1;
    }
};
```
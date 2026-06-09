### 解题思路
C++ 遍历

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        long int left = 0,right = x;
         long int center = 0;
        while (left<= right) {
            center = (left+right)/2;
            if (center*center <= x && (center+1)*(center+1)>x) {
                return center;
            }else if (center*center > x) {
                right = center-1;
            }else{
                left = center+1;
            }
        }
        return center;
    }
};
```
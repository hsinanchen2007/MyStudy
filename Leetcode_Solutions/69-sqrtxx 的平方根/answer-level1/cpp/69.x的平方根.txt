### 解题思路
利用二分解决，注意返回的是整数部分 小数部分省略，即下取整

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        double l=1,r=x;
        while(r-l>1e-7){
            double mid= (l + r) /2;
            if((mid*mid)>=x) r=mid;
            else l=mid;
        }

        return (int)r;
    }
};
```
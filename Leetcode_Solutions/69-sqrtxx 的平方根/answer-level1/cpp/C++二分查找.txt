```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;

        int left = 2;
        int mid;
        int right = x/2;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(mid < x/mid) left = mid + 1;   //注意 left 初始值为 0 时，这里 mid 可能取到 0，再做被除数时会报错
            else if(mid > x/mid) right = mid - 1;
            else return mid;
        }
        return right;
    }
};
```
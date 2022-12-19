
### 思路
根据反馈进行调整，使用二分查找
```cpp
class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        while(l <= r){
            int mid = l + (r -l) / 2; //相当于（l+r）/2，但用这种写法能防止溢出
            int g = guess(mid);
            if(g == 0)  return mid;
            else if(g == -1) r = mid - 1;
            else if(g == 1) l = mid + 1;
        }
        return 0;
    }
};
```

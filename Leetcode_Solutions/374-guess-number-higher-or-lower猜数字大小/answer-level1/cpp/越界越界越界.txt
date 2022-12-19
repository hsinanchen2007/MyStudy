### 解题思路
此处撰写解题思路

### 代码

```cpp
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int hig = n;
        while(low <= hig){
            int mid = low + (hig - low)/2; 
            if(guess(mid)==0){
                return mid;
            }else if(guess(mid)<0){
                hig = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
};
```

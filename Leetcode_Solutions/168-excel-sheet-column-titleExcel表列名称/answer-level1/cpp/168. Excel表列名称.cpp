## “伪”进制转换
**这道题的难点在于对应的数字不是从0开始的，所以每到一个26需要转换一次**
```cpp
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        int pop;
        while(n){
            pop = n%26;
            if(pop==0){ //如果n是26的整数倍
                pop=26;
                n = n-1;
            }
            ans += pop+'A'-1;//因为'A'是第1位，不是第0位，所以要减1
            n = n / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
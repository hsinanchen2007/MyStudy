### 代码

```cpp
#define Middle 1000000007
class Solution {
public:
    int cuttingRope(int n) {
        long long int result = 1;
        int time;
        if(n <= 3) return n-1;
        else if(n%3 == 0){
            time = n/3;
            result = 1;
        }
        else if(n%3 == 1){
            time = n/3 - 1;
            result = 4;
        }
        //n%3 == 2
        else{
            time = n/3;
            result = 2;
        }
        for(int i=0; i<time; i++){
            result = (result * 3) % Middle;
        }
        return result;
    }
};
```
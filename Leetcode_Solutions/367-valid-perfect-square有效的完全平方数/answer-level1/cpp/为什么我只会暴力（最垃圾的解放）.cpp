### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return true;
        bool isTrue = false;
        for(long i = 0; i <= num/2; i++){
            if(i*i==num){
                isTrue = true;
                break;
            }
        }
        return isTrue;
    }
};
```
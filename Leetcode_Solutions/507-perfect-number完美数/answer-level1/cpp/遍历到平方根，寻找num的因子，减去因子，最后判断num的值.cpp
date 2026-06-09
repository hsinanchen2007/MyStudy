### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;
        int res = num;
        for(int i=2;i*i<=res;i++){
            if(res % i ==0){
                num -= i;
                if(i*i != res){
                    num -= res/i;
                }
            }
        }
        return num - 1 == 0;
    }
};
```
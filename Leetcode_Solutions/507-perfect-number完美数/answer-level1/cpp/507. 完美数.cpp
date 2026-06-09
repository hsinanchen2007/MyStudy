### 解题思路
1.使用枚举法完成对完美数的判断。

### 代码

```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 0){
            return false;
        }
        
        int sum = 0;
        for(int i = 1;i * i <= num;i++){
            if(num % i == 0){
                sum += i;
                if(i * i != num){
                    sum += num / i;
                }
            }
        }
        return sum - num == num;
    }
};
```
### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/10772dea031ad2100d86b6e34a66c0fc2c352e11aeb57c95f6d5b392a1d5d7b9-image.png)

### 代码

```cpp
class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        while(sum>=10){
            sum = 0;
            while(num){
                int i = num%10;
                num/=10;
                sum+=i;
            }
            num = sum;
        }
        return sum;
    }
};
```
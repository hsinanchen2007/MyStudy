### 解题思路
![image.png](https://pic.leetcode-cn.com/1cd26c71ab30b426ea857211a1a7beb2f4bc993496e900748f9d07a3afb88d13-image.png)


### 代码

```cpp
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num) {
                sum += num%10;
                num = num / 10;
            }
            num = sum;
        }
        return num;
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/dd53c2d9e0c76ccba384dbd1b1c720cae6cdbb432b25f276be206fcf87216661-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)

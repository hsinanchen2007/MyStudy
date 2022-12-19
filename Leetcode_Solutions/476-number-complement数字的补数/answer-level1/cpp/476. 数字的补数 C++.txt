### 解题思路
1.利用数学规律。例如数字1100的补码等于1111 - 1100 = 0011。

### 代码

```cpp
class Solution {
public:
    int findComplement(int num) {
        long temp = 1;
        while (num >= temp){
            temp <<= 1;
        }
        return (temp - 1 - num);
    }
};
```
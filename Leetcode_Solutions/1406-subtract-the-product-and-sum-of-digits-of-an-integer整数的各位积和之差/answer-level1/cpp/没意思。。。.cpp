### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int sum = 0, product = 1;
    int subtractProductAndSum(int n)
    {
        while (n)
        {
            int temp = n - n / 10 * 10;
            sum += temp;
            product *= temp;
            n /= 10;
        }    

        // return (product > sum) ? (product - sum) : (sum - product);
        return product - sum;  
    }
};
```
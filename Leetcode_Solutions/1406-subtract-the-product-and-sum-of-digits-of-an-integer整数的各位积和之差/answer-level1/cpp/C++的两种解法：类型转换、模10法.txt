### 解题思路
第一种解法，将n转换为字符串。循环遍历字符串，同时将 字符-48 (48为0的ASCII码) 后即为数值，再进行操作。
第二种解法，直接while(n),在循环里对n进行模与除运算。

### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1, sum = 0;
        string str = to_string(n);
        for (auto c : str){
            int p = c-48;
            mul *= p;
            sum += p;
        }
        return (mul-sum);
    }
};
```
```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1, sum = 0;
        while(n){
            int p = n % 10;
            n /= 10;
            mul *= p;
            sum += p;
        }
        return (mul-sum);
    }
};
```
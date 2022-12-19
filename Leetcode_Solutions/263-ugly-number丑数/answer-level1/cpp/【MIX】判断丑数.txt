### 解题思路
不断除以因子

### 代码

```java []
class Solution {
    public boolean isUgly(int num) {
        if(num == 0)
            return false;
        while(num % 2==0) num/=2;
        while(num % 3==0) num/=3;
        while(num % 5==0) num/=5;
        return num==1;
    }
}
```
```python []
class Solution:
    def isUgly(self, num: int) -> bool:
        if num == 0:
            return False

        while num%2 == 0: num //=2
        while num%3 == 0: num //=3
        while num%5 == 0: num //=5
        return num == 1
```
```c++ []
class Solution {
public:
    bool isUgly(int num) {
        while(num % 2 == 0 && num>0)
            num = num/2;

        while(num % 3 == 0 && num>0)
            num = num/3;

        while(num % 5 == 0 && num>0)
            num = num/5;

        return num == 1;
    }
};
```
### 思路一：循环

### 代码

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 3 != 0) return false;
        while (n != 1) {
            if (n % 3 != 0) return false;
            n /= 3;
        }
        return true;
    }
};
```
### 简化代码
```c++
class Solution {
public:
    bool isPowerOfThree(int n) {  
        while (n && n % 3 == 0) {            
            n /= 3;
        }
        return n == 1;
    }
};
```


### 思路二：整数限制
用整数范围内最大数 % n 看是否为0。

### 代码
```c++
class Solution {
public:
    bool isPowerOfThree(int n) {  
        return n > 0 && (1162261467 % n == 0);
    }
};
```

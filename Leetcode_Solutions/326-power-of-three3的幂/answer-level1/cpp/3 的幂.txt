
##  解法1：循环

```
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        long m=1;
        while(m<n)
        {
            m*=3;
            if(m==n)
                return true;
        }
        return false;
    }
};
```

##  解法2：递归

```
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        else if(n==0) return false;
        else return isPowerOfThree(n/3)&&n%3==0;
    }
};
```

##  解法3：
3的幂次质因子只有3，而整数范围内的3的幂次最大是1162261467

```
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467%n == 0;
    }
};
```


### 解题思路1：数学
将问题转化为ax+by=z是否有解；
**定理**：a b x y 均为整数，如果ax+by=z有解，那么z一定是gcd(a,b)的倍数，否则无解。

### 代码
代码1：直接使用`gcd(x,y)`函数;
![image.png](https://pic.leetcode-cn.com/e0a936e33acde67d7c3181f7baab21e3ce5bdaeb964b9c0420118eb8bb6054ac-image.png)
代码2：手写辗转相除法；
![image.png](https://pic.leetcode-cn.com/9f0adae8f1fd9db26d0f1587d5becab8fccf0858d7eb4b6283f400d5f50e14f4-image.png)

```cpp []
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z)   return false; 
        else if(x+y==z)  return true;
        else if(x==0 || y==0)   return z==x || z==y;
        return z%gcd(x,y)==0;
    }
};
```
```cpp []
class Solution {
    int _gcd(int a, int b){
        if(a%b==0)
            return b;
        return gcd(b, a%b);
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z)   return false;
        if(x+y==z)    return true;
        if(x==0||y==0)  return z==x || z==y;
        // cout<<_gcd(x,y)<<endl;
        return z%_gcd(x,y)==0;

    }
};
```


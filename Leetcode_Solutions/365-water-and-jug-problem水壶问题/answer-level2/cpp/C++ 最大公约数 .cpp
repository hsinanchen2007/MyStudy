### 解题思路
判断条件有点丑陋，但是双100%通过。

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z>x+y)   return false;
        if(z==0)    return true;
        if(x==0&&y==0)  return false;
        int m=x>y?x:y;
        int n=x>y?y:x;
        int a = gcd(m,n);
        return !(z%a);
    }
    int gcd(int a,int b){
        int t;
        while(b!=0) {
            t=a%b;
            a=b;
            b=t;
        }
        return a;
    }
};
```
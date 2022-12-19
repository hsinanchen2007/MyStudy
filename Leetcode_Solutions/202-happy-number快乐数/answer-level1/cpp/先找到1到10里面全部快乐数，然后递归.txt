### 解题思路
用测试案例把10里面的快乐数找到（1和7），然后递归，最后经过一系列操作肯定得到个位数，这时候只要看看是不是快乐数完事了

### 代码

```cpp
class Solution {
public:
    bool isHappy(int n) {
        if(n==1||n==7) return true;
        else if(n>1&&n<=9) return false;
        int sum=0;
        while(n){
          int a=n%10;
          sum+=a*a;
          n-=a;
          n/=10;
        }
        return isHappy(sum);
    }
};
```
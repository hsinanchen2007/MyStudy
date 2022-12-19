### 解题思路：理解为纯暴力
2=1*1；
3=1*2；
4=2*2；
除了以上三个无规律，以下：
5=2*3；   8=2*3*3；  11=2*3*3*3；
6=3*3；   9=3*3*3；  12=3*3*3*3；
7=4*3；  10=4*3*3；  13=4*3*3*3;
综上看出规律，试着写了一下过了，复杂度为O(n);

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        int k=1,s=0,con=0;
        for(register int i=5;i<=n;i++){
            if(i-3*k>4){
                k++;
            }
            con=pow(3,k);
            s=(i-3*k)*con;
        } 
        return s;
    }
};
```
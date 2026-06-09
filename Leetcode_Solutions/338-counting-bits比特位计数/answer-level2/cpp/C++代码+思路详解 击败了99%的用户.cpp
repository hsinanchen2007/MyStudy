## 思路详解
f(0)=0
f(1)=f($2^0$)=1
f(2)=f($2^1$)=1
f(3)=f($2^1$)+f(1)=1+1=2
f(4)=f($2^2$)=1
f(5)=f($2^2$)+f(1)=1+1=2
f(6)=f($2^2$)+f(2)=1+1=2
f(7)=f($2^2$)+f(3)=1+2=3
…………
f(10)=f($2^3$)+f(2)=1+1=2
f(11)=f($2^3$)+f(3)=1+2=3
f(12)=f($2^3$)+f(4)=1+1=2
…………
f(n)=f($2^m$)+f($n-2^m$)=1+k

此处，$2^m$为小于n的最大2的指数幂，对于所有2的幂其比特位计数为1。

## 代码
```
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        int i=1;
        while(i<=num){
            res[i]=1; // 将 i=2^m 赋值为1
            for(int j=i+1;j<2*i&&j<=num;j++){ //计算 i+1到 2*i-1 之间对应的值
                res[j]=res[i]+res[j-i];
            }
            i=i*2;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/a8077dce37160f166658b482f87baebdbe58c135d1cf8d3fe9d9af123d74402b-image.png)


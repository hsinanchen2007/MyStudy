![image.png](https://pic.leetcode-cn.com/805c2885477fda15f34f434434495bbd7577f4d27d7adda5e5b57504ded2a19f-image.png)
看gcd(x,y)能否整除z，再判断一下特殊情况即可，参见数论裴蜀定理
```
class Solution {
public:
    int gcd(int a,int b){
        if(a>b)swap(a,b);
        if(a==0)return b;
        while(a!=b){
            while(a>b){
                a-=b;
            }
            while(b>a){
                b-=a;
            }
        }
        return a;
    }
    bool canMeasureWater(int x, int y, int z) {
        if(z==0)return true;
        if(x==0&&y==0&&z!=0)return false;
        if(x==0&&y!=0){if(z%y==0)return true;
        else return false;}
        if(y==0&&x!=0){if(z%x==0)return true;
        else return false;}
        if(x+y<z)return false;
        int k=gcd(x,y);
        if(z%k==0)return true;
        return false;
    }
};
```

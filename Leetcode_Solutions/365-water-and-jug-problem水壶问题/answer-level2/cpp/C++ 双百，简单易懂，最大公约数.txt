可以把x和y两壶来回倒的过程看作辗转相除法，这样两个数的最大公约数就代表两个壶组合可以获得的升数，
再判断这个数字是不是z的约数就好，对于可能除数等于0的情况特殊处理
```
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0) return true;
        if(x==0&&y==0) return z==0;
        int temp;
        if(x==0||y==0)
            temp=x==0?y:x;
        else if(z>x+y)
            return false;
        else
            temp=mostcommmon(x,y);
        return z%temp==0;
    }
    int mostcommmon(int x,int y)
    {//求最大公约数
        if(x<y) swap(x,y);
        if(x%y==0) return y;
        else return mostcommmon(y,x%y);
    }
};
```

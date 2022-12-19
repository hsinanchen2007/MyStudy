将容量小的放左边，从右边杯子加水，向左边匀，左边满了就倒掉，从右边匀，直到形成循环。中间判断是否满足条件。
```
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x>y){
            int tmp=x;
            x=y;
            y=tmp;
        }
        if((x+y)==z) return true;
        if(!z) return true;
        int a=0,b=0;
        while(1){
            if(b==0){//右侧加水，匀向左边
                b=y-x+a;
                a=x;
                if( (a+b)==z || b==z) return true;
            }
            if(a==x){//左侧倒水，从右边匀
                a=min(b,x);
                b=max(0,b-x);
                if((a+b)==z) return true;
                if( (x==a||!a) && (!b || b==y)) return false;
            }
        }
        return false;
    }
};
```

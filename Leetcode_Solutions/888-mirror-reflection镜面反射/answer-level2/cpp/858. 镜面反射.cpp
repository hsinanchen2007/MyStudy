模拟方法。

也可以求最小公倍数，懒得写了……

```
class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(q==0)return 0;
        if(q==p)return 1;
        bool left=false;
        bool up=true;
        int h=q;
        while(true)
        {
            if(up)
            {
                h+=q;
                if(h>p)
                {
                    h=2*p-h;
                    up=false;
                }
                left=!left;
                
                if(h==p)
                {
                    return left?2:1;
                }
            }
            else
            {
                h-=q;
                if(h<0)
                {
                    h*=(-1);
                    up=true;
                }

                left=!left;

                if(h==0 && !left)
                {
                    return 0;
                }
            }
        }
    }
};
```

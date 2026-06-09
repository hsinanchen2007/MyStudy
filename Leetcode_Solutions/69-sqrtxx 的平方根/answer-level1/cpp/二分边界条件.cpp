
```
class Solution {
public:
    int mySqrt(int x) {
        long left=1;
        long right=x;
        int medium;
        if(x<1) return 0;
        while(left<right-1)
        {
             medium=(left+right)/2;
            if((long)medium*medium>x)
                right=medium;
            else if((long)medium*medium<x)
                left=medium;
            else
                return medium;
        }
        
        return left;
    }
};

```
此题 对于边界条件有个坑；要注意此处耍了一下小技巧，在二分左值和右值相差为1的时候就停止查找，输出左值；因为在这里，有个对中值取整数的操作，在取整后始终有left==medium则会死循环。

取整操作的误差为1，故而在这里限制条件改成包含1在内的范围left<right-1;这里减一很精髓。。
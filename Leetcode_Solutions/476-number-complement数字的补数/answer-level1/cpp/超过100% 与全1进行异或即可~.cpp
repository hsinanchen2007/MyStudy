```
class Solution {
public:
    int findComplement(int num) {
//先找出比num大的第一个全1数
        long a = 1;
        while(1)
        {
            if(a > num)
                break;
            a = a * 2;
        }
        a = a - 1;
        return a ^ num;
    }
};
```

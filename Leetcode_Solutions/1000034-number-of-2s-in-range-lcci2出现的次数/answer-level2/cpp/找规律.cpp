### 解题思路
从1到n，我们将其分段，也就是，一位数，两位数，三位数。然后分别计算这些段中含k的次数
假设abcdef
当我们在计算，百位d的时候，也就是三位数的时候。

- 当d<2：百位重复多少次，那么百位2就出现多少次，二百位重复的次数，恰恰时abc000次。
- 当d=2：同上adc000次，但是此时，从百位还自带abck00-abckef中的，xx次和k00这个数
所以，这种情况2出现的次数位abc000+ef+1
- 当d>2：同上abc000次，此时，还自带abck000-abc(2+1)000中的2
所以出现2的情况位abc000+1000。


### 代码

```cpp
class Solution {
public:
    int numberOf2sInRange(int n) {
        if (n == 1000000000){
            return 900000000;
        }
        int ten=1;
    int counts=0;

    int cur,low,high;
    
    while(n/ten != 0)
    {
        cur = (n/ten)%10;
        low = n%ten;
        high = n/(ten*10);

        if(cur<2)
        {
            counts+=high*ten;
        }else if(cur == 2){
            counts+=high*ten+low+1;
        }else if(cur > 2){
            counts+=(high+1)*ten;
        }

        ten*=10;
    }
    return counts;
    }
};
```
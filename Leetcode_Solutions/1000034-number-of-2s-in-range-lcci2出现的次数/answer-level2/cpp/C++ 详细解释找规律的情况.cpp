### 解题思路
此题目和LeetCode 233题基本一致，个人建议两道题目可以一起看。
本题是找规律的题目。
我们可以推导出相应的公式：
0-9可以发现只有2符合。
0-99可以发现，一共有十位数上可以排0-9，个位数为2，共10*1 = 10个；
然后，需要注意十位数为2的特殊情况，即为10 + 10 = 20。
0-999可以发现，共有10个0-99的情况，故为10 + 20 = 200；
而对于2xx（100-199）而言，又有100个数据，故为200+100 = 300。
同样的道理可以一直延续下去。

```
0 - 9:    10 * 0 + 1        = 1; //个位数1个2
0 - 99:   10 * 1 + 10      = 20; //0-9都可以为十位数，当2x时，0-9都可以出现；
0 - 999:  10 * 20 + 100     = 300;//0-9都可以为百位数，当2xx时，0-99都可以出现；
0 - 9999: 10 * 300 + 1000   = 4000;//0-9都可以为千位数，当2xxx时，0-999都可以出现
```

因此，我们可以整理一下，对于一个数而言：
设定：
当前位数为n; \quad  需要乘的因子为f; \quad 后面需要加的数据l; \quad 当前位置之后的所有数c；
因此，我们可以对前面的数据进行等式的体现：
```
l = 10 * l;(1,10,100,1000.....)
f = 10 * f + l;(1,20,300,4000......)
```
故进行情况的说明：
- 小于2：res = n * f;
- 等于2：res = n * f + c + 1;
- 大于2：res = n * f + l;
这里之所以等于2的时候不一样，是因为，等于2的时候2xx取决于xx的数目，所以，要算后面的位数。
那么迭代关系就很明了了。
```
c = c + n * l;  (算n位后面的位数，也就是2xx中的xx)；
f = 10 * f + l; (算当前位数该有的值，也就是1，20，300，4000)；
l = 10 * l;     (算后面应该加的数，也就是1，10，100，1000)；
```
故，就可以很好的得到结果了。

### 代码

```cpp
class Solution {
public:
    //和1出现的次数，异曲同工。
    //找个位数，十位数的2。
    int numberOf2sInRange(int n) {
        int current_index = 0;
        long last_index = 1;
        long factor = 0;
        int count = 0;
        while(n != 0){
            int low_digit = n % 10;
            //当为2的时候，其后面的所有数据都是会被加入的，所以，需要算当前index +1；
            // low_digit * factor 就是 前面的一部分
            //current_index + 1代表了2后面跟着的位数。
            if(low_digit == 2) count = count + (low_digit * factor + current_index + 1);
            //last_index则表明了后面不断更新的数据
            else if(low_digit > 2) count = count + (low_digit * factor + last_index);
            //
            else count = count + low_digit * factor;
            current_index = current_index + low_digit * last_index;
            factor = 10 * factor + last_index;
            last_index = last_index * 10;
            n = n / 10;
        }
        return count;
    }
};
```
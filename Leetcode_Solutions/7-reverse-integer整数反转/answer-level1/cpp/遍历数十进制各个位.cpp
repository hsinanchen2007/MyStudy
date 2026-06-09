### 解题思路
执行用时 : 4 ms , 在所有 C++ 提交中击败了 74.20% 的用户 
内存消耗 : 7.6 MB , 在所有 C++ 提交中击败了 100.00% 的用户

这个题是easy，但是如果加上不能使用long的限制，并且不能使用额外的内存。对于边界的判断就会难很多。
这道题的关键就是要知道如何具体的遍历一个数字的各个位，我的方法是先找到最高位，然后从高到低依次取。
方法是先找到最高位对应的10的倍数，然后除以这个倍数，可以得到这个位。接下来用 x - 这个位的值 * 10的倍数。
可以得到抛去高位后的数，然后重复刚刚的过程。就可以得到所有的位。

下面是具体代码

### 代码

```cpp
class Solution {
public:
    long msbNum(long xx){
        long num = 1, res = 0;
        while(num * 10 <= xx){
            num *= 10;
        }
        return num;
    }

    long getRes(long xx){
        long res = 0;
        long divide = msbNum(xx), mul = 1;
        //cout << divide << endl;
        while(divide > 0){
            res += (xx/divide) * mul;
            xx -= (xx/divide)*divide;
            mul *= 10; divide /=10;
        }
        return res;
    }

    int reverse(int x) {
        int sign = x > 0? 1: -1;
        long xx = long(x) * sign;
        long res = getRes(xx); 
        //cout << res << endl;
        res *= sign;
        if(sign > 0){
            return res > INT_MAX? 0: res;
        }else{
            return res < INT_MIN? 0: res;
        }
        return 0;
    }
};
```
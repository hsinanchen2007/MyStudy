### 解题思路
这道题不难，其实就是先找x在十进制情况下的最高位，然后单独每次取出x十进制每一位进行比较。
取高位： msb = x/divide
取低位： (x%mul)/(mul/10)

此外，这次提交错了2个地方，分别记录在下面代码的error1与error2中。
error1: 是错在当x = 10的时候，不进行比较直接output，需要在divide > mul中加入等于的判断
error2: 是错在res*10可能会超过int的表示范围，当x是INT_MAX的时候，这个运算会越界。

这种int类型的case，往往都需要尝试接近越界的数字才行!

### 代码

```cpp
class Solution {
public:
    int msbNum(int x){
        long res = 1;
        while(res * 10 <= (long)x){//error2: res * 10 <=  x
            res *= 10;
        }
        return res;
    }
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int divide = msbNum(x), mul = 10;
        //cout << divide << endl;
        while(divide >= mul){ //error1: divide > mul
            int msb = x/divide, lsb = (x%mul)/(mul/10);
            //cout << "msb: " << msb << " lsb: " << lsb << endl;
            if(msb != lsb) return false;
            x -= (x/divide)*divide;
            x -= (x%mul);
            divide /= 10; mul *= 10;
        }
        return true;
    }
};
```

### 结果
执行用时 : 12 ms , 在所有 C++ 提交中击败了 85.80% 的用户 
内存消耗 : 7.5 MB , 在所有 C++ 提交中击败了 100.00% 的用户
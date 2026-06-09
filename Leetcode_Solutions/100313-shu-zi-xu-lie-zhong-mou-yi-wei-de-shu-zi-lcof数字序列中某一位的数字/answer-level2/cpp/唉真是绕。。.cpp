### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10)return n;
        //运行到这则第n位数一定是"2"位以上
        int digits;
        long long count = 0;  //防止越界！！务必注意！！
        long long pre = 0;  //记录digits-1位数所占的总个数
        for(digits = 1; ; ++digits)
        {
            if(digits == 1)
                count += 10;  //0-9共10个数
            else
            {
                //pre存储当前位数的上一位有多少数，比如digits=2，2位数的前面是1位数，共有10个
                //例如digits=3，3位数的前面是2位数共180个+1位数共10个=190个
                pre += (digits > 2 ? (9 * pow(10, digits - 2) * (digits-1)) : 10);
                count += (9 * pow(10, digits-1) * digits);  //例如digits=2表示两位数共占多少个
            }
            if(count > n)break;
        }
        //现在已经计算得出digits，即第n位数对应的是几位数
        //现计算出这几位数是什么数
        int target = 0;
        int base = pow(10, digits-1);  //digits=2,base=10,2位数的第一个数是10
        target = base + ((n - pre) / digits);  //计算得出这第n位数对应的数是啥
        //接下来计算第n位数对应的是target的第几位
        int index = (n-pre) % digits;  //若index==0表示target的个位，index==1表示target的十位
        stack<int> s;  //用于存储target的个位、十位、百位...
        while(target)
        {
            s.push(target % 10);
            target /= 10;
        }
        while(index)
        {
            s.pop();
            --index;
        }
        return s.top();
    }
};
```
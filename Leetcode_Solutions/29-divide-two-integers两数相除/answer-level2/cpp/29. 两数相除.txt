### 解题思路
二分迭代法查找商：
1、每次迭代中：除数乘2，直到大于被除数，过程中循环次数乘2，作为商的一部分
2、下一次迭代：除数减去步骤1中不大于被除数的除数（除数每次循环都乘2后的数，不大于被除数）
3、迭代结束条件：除数大于被除数，迭代函数返回0

注意：要考虑到int的范围，适当的时候使用long型，否则会溢出。

详细步骤参考代码注释。

### 代码

```cpp
class Solution {
public:

    int divide(int dividend, int divisor) {
        if(divisor == 0 || dividend == 0){//除数为0的情况
            return 0;
        }

        if(divisor == 1){//除数为1的情况
            return dividend;
        }

        if(divisor == -1){//除数为-1
            if(dividend > INT_MIN){
                return -dividend;
            }
            return INT_MAX;
        }

        //转存除数与被除数 ,因为int的范围为：-2147483648~2147483647，所以需要使用long型的整数来转存，否则会溢出
        long a_divedend = labs(dividend);//被除数
        long b_divisor = labs(divisor);//除数

        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)){
            return itDiv(a_divedend,b_divisor);
        }else{
            return -itDiv(a_divedend,b_divisor);
        }
    }

    int itDiv(long a, long b) {//防止int类型溢出
        if(a < b){//迭代结束的条件:如果除数大于被除数，则商为0，也就是返回0
            return 0;
        }

        long temp_b = b;//每次循环除数temp_b都乘上2，也就是二分法去找商，直到temp_b大于被除数
        long count = 1;//相当于商，每次循环都乘2，因为除数乘2了

        while(a >= (temp_b + temp_b)){//开始循环找商，结束的条件：temp_a < temp_b
            count += count;
            temp_b += temp_b;
        }

        return count + itDiv(a - temp_b,b);//减去已经计算过的除数重新迭代
    }
};
```
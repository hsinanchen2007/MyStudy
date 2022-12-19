题目要求即将num二进制各位由1变成0，0变成1，由此想到将各位与1做异或操作即可。如何找到与num二进制有效位（没有前导零位）个数相同且都是1的数呢？
只要找到比num最高1位的位置高一位（左边）就行了，此时该数必然大于num，如num=5（101B）时，这个数为8（1000B），将其减1，则得到与num有效二进制位数相同且各位都为1的数。如8-1=7（111B）

```
    public int findComplement(int num) {

        long num0 = 1;

        while(num0 <= num)
            num0 = num0 << 1;

        num0 -= 1;

        return (int)num0 ^ num;
    }
```

先上代码```javascript []
```
public int reverseBits(int n) {
        int i = 0, j = 31, retVal = 0, temp;
        while (i < j) {
            temp = n >> i;
            temp &= 1;
            temp <<= j;
            retVal |= temp;
            temp = n >> j;
            temp &= 1;
            temp <<= i;
            retVal |= temp;
            i++;
            j--;
        }
        return retVal;
    }
```
首先应该感谢leetcode大神的思路，阿弥陀佛！

1:取出尾处二进制位，移到首位
2:取出首位二进制位，移到尾处
夹逼遍历一次，首位完成对调。
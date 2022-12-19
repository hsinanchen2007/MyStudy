### 解题思路
首先要找到规律：
1位数有10个，位数总数是10 * 1
2位数有(99 - 10) + 1 = 90个，位数总数是90 * 2
3位数有(999 - 100) + 1 = 900个，位数总数是900 * 3
.
.
.
bitCount位数有9 * pow(10, bitCount - 1)个,位数总数是9 * pow(10, bitCount - 1) * bitCount

通过上面的位数总数累加后(numCount)不断和n做比较后， 找到小于等于n的最大的累加总数对应的bitCount的值求结果


剩下的位数：
    d = n - numCount

剩下的数的个数：
    t = d / bitCount

最后的数字：
    lastNum = t + pow(10, bitCount - 1)

d所对应的数字的位数:
    bitIndex = (n - numCount) % bitCount
    bitIndex = (bitCount - 1) - bitIndex   //高低位调转

最后就可以用lastNum和bitIndex求得对应数字，注意用long避免int的数值溢出

### 代码

```csharp
public class Solution {
    public int FindNthDigit(int n) {
        if(n <= 9)
        {
            return n;
        }

        long longN = (long)n;
        long numCount = 10;
        long bitCount = 2;
        long minNum = 10;   //pow(10, bitCount - 1)
        for(int i = 1; true; i++)
        {
            long c = numCount + 9 * minNum * (i + 1);
            if(c > longN)
            {
                break;
            }

            minNum *= 10;
            numCount = c;
            bitCount++;
        }

        long d = longN - numCount;
        long t = d / bitCount;
        long bitIndex = (bitCount - 1) - d % bitCount;

        long lastNum = minNum + t;

        long j = 0;
        while(lastNum != 0)
        {
            long temp = lastNum % 10;

            if(j == bitIndex)
            {
                return (int)temp;
            }

            lastNum /= 10;
            j++;
        }

        return 0;
    }
}
```
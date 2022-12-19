### 解题思路
来自剑指offer
本题与上一题不同的是，无法直接采用异或运算，来抵销。
但是依然可以沿用位运算的思路。
如果一个数字出现3次，那么对应的二进制的位数也是出现了3次。
如果把所有出现三次的数字的二进制的对应位数相加。那么每一位应当都可以被3整除，因为每一位肯定是3的倍数.
如果把数组的所有数字全部相加，并转换为2进制数，按位存储。
	如果某一位对3取余数为0，则表示要求的那个数字对应的位数为0，否则对应的位置的数就是余数（有且只有一种可能就是1）。
最后边处理边恢复，就可以得到最终的值。

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int[] bitSum = new int[32];
        for(int i=0; i<nums.length; i++){
            int bitMask=1;
            for(int j=0; j<32;j++){
                int bit = nums[i]&bitMask;
                if(bit!=0){
                    bitSum[j]+=1;
                }
                bitMask = bitMask << 1;
            }
        }
        int result=0;
        for(int i=0; i<32; i++){
            result += (int)(bitSum[i]%3)*Math.pow(2, i);
        }
        return result;

    }
}
```
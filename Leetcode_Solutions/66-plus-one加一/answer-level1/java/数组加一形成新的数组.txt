### 解题思路
必须从末尾开始遍历，元素加一后对10求余数，出现第一个不为0的元素就可以返回，不然就得开辟加1的空间存储新的数组，只需将第一个元素赋值为1即可，其他元素均为初始值0

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for(int i = digits.length - 1; i >= 0; i--){
            digits[i]++;
            digits[i] = digits[i] % 10;//就是求加一后的余数
            if(digits[i] != 0){//有第一个不为0的元素就可以直接返回结果
                return digits;
            }
        }
        //到了这一步说明训练遍历完了，所有元素均为0
        digits = new int[digits.length + 1];//必须开辟个比原本数组内存多1的空间，全9的情况
        digits[0] = 1;//多出来的存储空间存进位1，其他元素都为0，不需赋值
        return digits;
    }
}
```
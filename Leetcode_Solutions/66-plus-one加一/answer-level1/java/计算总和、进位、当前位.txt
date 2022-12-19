### 解题思路
题目比较简单，初始化进位为1，相当于数组的最低位得到了一个进位，从后向前遍历数组，加上进位，修改当前元素值，保存进位。
注意：当最后一次的进位不为0时需要重新new一个数组，长度为之前的长度+1，然后数组拷贝

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {

        int nextVal = 1;
        for(int i=digits.length - 1;i>=0;i--){
            int sum = digits[i] + nextVal;
            nextVal = sum/10;
            int curVal = sum % 10;
            digits[i] = curVal;
            if(nextVal == 0){
                break;
            }
        }
        int[] result = new int[digits.length+1];
        if(nextVal>0){
            result[0] = nextVal;
            System.arraycopy(digits,0,result,1,digits.length);
            return result;
        }else{
            return digits;
        }
    }
}
```
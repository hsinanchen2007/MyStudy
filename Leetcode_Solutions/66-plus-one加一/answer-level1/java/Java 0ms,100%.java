### 解题思路
正常加1，进位单独保存，最后digits[0]大于10则建立新的数组并新数组[0]为1，后边复制过去
重点在，改变数组个数大小只取决于digits[0]正常计算是否大于10，建立新的数组首位只可能是1

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
    int temp = 0;
    int count = digits.length-1;
    
    

    for(int i = count;i>=0;i--)
    {
        if(i == count)
            digits[i]++;
        digits[i] += temp;
        if(digits[i] >= 10)
        {
            digits[i] = digits[i]%10;
            temp = 1;
        }
        else
            temp = 0;
        
    }
    if(temp != 0)
    {
        int[] rev = new int[digits.length+1];
        rev[0] = 1;
        for(int n = 1;n<rev.length;n++)
        {
            rev[n] = digits[n-1];
        }
        return rev;

    }
       
    return digits;
  
    }
    
}
```
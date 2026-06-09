### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findNthDigit(int n) {
        //定义double类型是为了防止数组越界
        double left=(double)n;
        double lastSum=0;
        int i=1;
        double num=0;
        if(n<10) return n;
        while(left>0)
        {
            lastSum+=num;
             num=9*Math.pow(10,i-1)*i;
            left=left-num;
            i++;
        }
        i=i-1;
        int beginIndex=n-(int)lastSum-1;
        int div=(int)Math.pow(10,i-1);
        int number=div+(beginIndex)/i;
        int numberIndex=beginIndex%i;
        return Integer.toString(number).charAt(numberIndex)-'0';
    }
}
```
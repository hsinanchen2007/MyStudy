### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        //用到了java的函数Integer.parseInt(String.valueOf(s.charAt(i)))，并不通用
        // String s = String.valueOf(n);
        // int multi = 1;
        // int sum = 0;
        // for(int i = s.length()-1;i>=0;i--)
        // {
        //     int num = Integer.parseInt(String.valueOf(s.charAt(i)));
        //     multi = multi * num;
        //     sum = sum + num;
        // }
        // return multi - sum;
  int sum = 0;
        int product = 1;
        while(n>0)
        {
            sum = sum + n%10;
            product = product * (n%10);
            n=n/10;
        }
        return product - sum;
    }
}
```
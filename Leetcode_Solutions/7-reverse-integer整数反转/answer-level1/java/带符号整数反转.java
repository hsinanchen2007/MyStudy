### 解题思路
判断数字是否达到临界值，即取反后还是负数，如果是说明超出范围，返回0；转成正数，转成s字符串，取反，转为Double类型，判断是否超出范围，如果是返回0，不是转成整数，并转为原来是正数就是返回正数，负数就转为负数返回。

### 代码

```java
class Solution {
    public int reverse(int x) {
        String state = "";
        int nx = x;
        if(x<0)
        {
            state = "-";  
            nx = -x;     
            if(nx<0)
            {
                return 0;
            }
        }
       
        String sx = String.valueOf(nx);

        StringBuffer sxb = new StringBuffer(sx);
        sx = sxb.reverse().toString();
        Double dsx = Double.valueOf(sx);
        if(dsx>Math.pow(2,31)-1)
        {
            return 0;
        }

        if(state.equals(""))
        {
            return dsx.intValue();
        }
        else 
        {
            return -dsx.intValue();
        }
    }
}
```
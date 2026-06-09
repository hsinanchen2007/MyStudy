

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        //思想：由于只能换1位。如果这个数字中有6，把最高的那一位换掉就行。我们可以把它转化成一个字符串问题处理。
        String s=""+num;  //整数转化为字符串
        char[] chars=s.toCharArray();
        for(int i=0;i<chars.length;i++)
        {
            if('6'==chars[i])
            {
                chars[i]='9';
                break;
            }
        }
        return Integer.parseInt(new String(chars));
    }
}
```
### 解题思路
这一题其实不难，只要总结了题目信息，基本上都能看出来一些：
1.小值放在大值之前，要用大值减去小值
2.小值放在大值之后，要用大值加上小值

再详细一点就是：第一次先取出输入字符串的第一个字符，然后从第二个字符开始遍历；然后比较以后按照上面的规则去做运算，以后每次把“第二个”当做“第一个”这样不断替换。直到最后。

但是这一题可能会被难住的地方在于：**题目中是默认输入合法的**！！！
我一开始就是在这里考虑了好久。。。

### 代码

```java
import java.util.*;

class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        int preNum = getValue(s.charAt(0)); 
        for(int i = 1;i < s.length(); i ++) {
            int num = getValue(s.charAt(i));  
            if(preNum < num) {
                sum -= preNum;
            } else {
                sum += preNum;  
            }
            preNum = num;  
        }
        sum += preNum;
        return sum;
    }
    
    private int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
}

```
### 解题思路
解题思路见 ↓↓↓
![gzh.jpg](https://pic.leetcode-cn.com/6ace4ef6d026462a538f5deceafe577af5cdf0f0a38677f6680ef350f9050200-gzh.jpg)

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int len = Integer.toBinaryString(n).length(); //求出整数对应二进制的长度
        String num = Integer.toBinaryString(n);       //将整数转换为二进制 
        int count = 0;                                //计数器
        for(int i=0;i<len;i++){                       //遍历二进制各个位
            if( num.charAt(i)== '1'){                 //如果为 ‘1’
                count = count + 1;                    //计数器加1
            }
        }
        return count;
    }
}
```
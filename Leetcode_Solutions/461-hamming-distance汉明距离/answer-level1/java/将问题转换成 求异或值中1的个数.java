### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int hammingDistance(int x, int y) {
        int s=x^y;      //求x与y异或之后的值，转换为二进制就可以得到一的位置
        int count=0;
        while(s>0){
            if((s & 1)==1){     //当s值得最后一位与一为1是计数加一
                count++;
            }
            s=s>>1;     //s右移一位
        }
    return count;
    }
}
```
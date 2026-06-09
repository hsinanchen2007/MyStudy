### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reverse(int x) {
        long y = x; //使用一个比int范围更大的long类型的变量y来接收x
        //由于int类型的x反转后，可能会超过int表示的范围，所以就使用long类型的数据来接收
        long result = 0; 

        do {
            long i = y % 10;  //获取y的最后一位上的数值
            result = 10 * result + i;
        }while((y /= 10) != 0);

        if (result > Integer.MAX_VALUE || result < Integer.MIN_VALUE) {
            return 0;
        }

        return (int)result;
    }
}
```
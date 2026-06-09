### 解题思路
蛮笨的一个方法......
#### 首先将数字转成字符串，判断字符串是否含有"6"?
1. 若不含有直接返回；
2. 若含有则取出第一个出现"6"的下标并加1,就是6在第几个位置，设为position；获取字符串的长度length
* 若是"96"，则position为2，length为2。(length-position)=0，没有0，只需要加3，就可以变为"99"
* 若是"966",则position为2，length为3。(length-position)=1，1个0，只需要加30，就可以变为"996"
......
#### 总之，需要做到的只是确定是加3、30、300、3000。
#### 所以只需要判断3的后面是几个0就好了。

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        String str = String.valueOf(num);
        int position = str.indexOf("6") + 1;
        int length = str.length();
        int multi = 1;
        if (position > 0) {
            for (int i=0; i < (length-position); i++) {
                 multi *= 10;
            }
            num += multi*3;
            return num;
        } else {
            return num;
        }
    }
}
```
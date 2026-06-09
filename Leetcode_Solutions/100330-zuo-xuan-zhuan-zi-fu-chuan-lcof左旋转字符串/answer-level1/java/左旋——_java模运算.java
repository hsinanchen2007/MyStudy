### 解题思路
首先，左旋让我想起来钟表旋转，然后就引申到了模运算。
获取字符长度，然后通过字符串建立一个字符数组，以及另一个等长得空数组为了装乘返回字符串.
然后遍历数组，然后依次赋值给那个空数组模运算所得位置即可。
（注意：java取余之后如是负数需要与模相加（这一点跟python不同）;映射方向是从before-->after,after的下标要取计算结果）

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        char[] before = s.toCharArray();
        int len = s.length();
        char[] after = new char[len];
        for(int i=0;i<len;i++){
            int num = (i-n)%len;
            after[num<0?num+len:num]=before[i];
        }
        return new String(after);
    }
}
```
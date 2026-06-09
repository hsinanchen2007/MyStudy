第一次写题解，主要是记录自己的解题想法，有不好的地方请包涵并指出我下次改正。
L * * D * * R
E * O E * I I
E C * I H * N
T * * S * * G

首先分析题目描述，直接看变换后的Z字形态，LDR和TSG属于首尾两行，中间是没有空格字符的（此处用 * 表示）.
L和D代表了每一个字符之间的间距 2*（number-1），也就是说如果忽略掉中间代空格的列，其实每一个索引的相差就是上述公式

根据图形分析可知，假如输入数为number,那么从0-number之间就是L E E T字符串中的索引

我们一行行遍历（结合代码看更清楚）
第一行 从0开始
L的索引就是0，因为首尾两行没有空格字符，所以直接找下一个索引字符，0+2*(number-1)
然后再在下一个索引的基础上找寻等同间距的索引，直到被找寻索引的值大于字符串的长度时停止循环

然后找第二行，此时E=1，中间有空格字符。等同分析可知 LEETCOD的索引就是 0123456，分析可知等加数前后两个数之和均相等，所以E和O的索引相加就等于间距，所以找到O=6-1=5;
所以在一个间距长度内需要保存两个值先保存E再保存O 然后E、O同时找到下一个索引，同时因为E总是小于O的索引的，所以E的长度大于字符串长度时退出循环。以此类推
代码如下：
```
public String convert(String s, int numRows) {
        if(numRows==1)return s;
        // Z字形变换跳跃间隔 中间跳跃的索引数量
        int len = 2*(numRows-1);
        StringBuilder sb = new StringBuilder();
        for(int i =0;i<numRows;i++){
            int one = i;
            int second = len-i;
            while(one<=s.length()-1){
                // 首尾两行只需要执行一次
                sb.append(s.charAt(one));
                one +=len;
                if(i!=0&&i!=numRows-1&&second<=s.length()-1){
                    sb.append(s.charAt(second));
                    second +=len;
                }
            }
        }
        return sb.toString();
}
```



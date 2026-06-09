### 解题思路
此处撰写解题思路
我的思路:
    先将整数转换成字符串操作，由于不知道次数的情况下使用了死循环，在死循环中用了substring方法，将截取指定
字符为字符串，在转换成整形进行相加，截取的位置也往后移动
    再判断移动的位置是否已经到达了字符串的尾部了，如果到达了尾部
    再将已经运算好的整数转换成字符串，再判断一下这个字符串的长度
是否大于等于2，如果大于等于2的时候，将运算好的整数重新赋值给原字符串，再将这个运算好的整数赋初值为0，防止下次运算累加的情况！
然后i也赋初值为0；
如果运算好的整数转为字符串的长度小于2的时候直接返回当前运算的结果的值！
### 代码

```java
class Solution {
    public int addDigits(int num) {
       String str=""+num;
       int sum=0;
       int i=0;
       int k=0;
        while(true){
            sum+=Integer.parseInt(str.substring(i,i+1));
            
            i++;
            if(i>=str.length()){
                if(String.valueOf(sum).length()>=2){
                    str=String.valueOf(sum);
                    sum=0;
                    i=0;
                }else{
                    return sum;
                }
            }
        }
    }
}
```
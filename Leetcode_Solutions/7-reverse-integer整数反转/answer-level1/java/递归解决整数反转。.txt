以123为例，计算123的反转数，可以理解为计算3和余下的12反转之和，然后再计算12……
利用long来计算，避免在计算中频繁比较，最后通过与int的最大最小值比较来解决溢出问题。
运行结果如下：
执行用时 :
1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37 MB, 在所有 Java 提交中击败了5.07%的用户

**没有注释的版本**
```
class Solution {
    public int reverse(int x) {
        long ret = recursionReverse(0,x);
        if(ret > Integer.MAX_VALUE || ret < Integer.MIN_VALUE){
            return 0;
        }
        return (int)ret;
    }
    public long recursionReverse(long r, long x) {
        if(0 == x){
            return r;
        }
        return recursionReverse(r*10+x%10,x/10);
    }
}
```

**加注释的版本**

```
class Solution {
    public int reverse(int x) {
        //先按Long型递归计算，解决溢出问题
        long ret = recursionReverse(0,x);
        //判断溢出
        if(ret > Integer.MAX_VALUE || ret < Integer.MIN_VALUE){
            return 0;
        }
        //没溢出，转型
        return (int)ret;
    }
    /***
     * 递归计算，123转型可以理解为，3和余下的12反转之和，r中存储的就是已经反转的部分。
     **/
    public long recursionReverse(long r, long x) {
        //最后x为0时退出递归，直接返回r
        if(0 == x){
            return r;
        }
        //其他情况递归计算，r乘以10是以为每次要前进一位。
        return recursionReverse(r*10+x%10,x/10);
    }
}
```

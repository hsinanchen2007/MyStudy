### Java 参考 Integer类的处理方式
参考了`Integer.parseInt(String s, int radix)`方法对边界的处理方式, **用负数来表示正负数的边界**
1. 这样正数的边界就是`-Integer.MAX_VALUE`,负数是`Integer.MIN_VALUE`
2. 然后我们同样也用负数来保存结果, 这样我们按负数累减就是：`res=res*10-digit`
3. 然后我们需要对`res`做判断防止溢出 也就是 `res*10-digit>=limit (负边界)`,但是直接判断可能会溢出,所以进行移项,变换为 `res<(limit+digit)/10`
4. 最后如果是正数就返回 `-res`,负数就返回`res`

```java
class Solution {
    public int myAtoi(String str) {
        if(str==null || str.length()<=0) return 0;
        //正负数的最大最小值
        int MAX=Integer.MAX_VALUE,MIN=Integer.MIN_VALUE;
        int res=0,index=0;
        //过滤空格
        while(index<str.length()&&str.charAt(index)==' ')index++;
        if(index==str.length()) return 0;
        //取正负号
        char firstChar=str.charAt(index);
        boolean positive=true;
        if(!isDigit(firstChar)){
            if(firstChar!='+'&&firstChar!='-') return 0;
            index++;
            positive = firstChar!='-';
        }
        //用负数保存正负数的边界，这样不会溢出
        //正数 -2147483647
        //负数 -2147483648
        int limit=positive?-MAX:MIN;
        //过滤0
        while(index<str.length()&&str.charAt(index)=='0')index++;
        //取每一位,在非字符截止
        while(index<str.length()&&isDigit(str.charAt(index))){
            int digit=str.charAt(index++)-'0';
            if(res<(limit+digit)/10){
                return positive?MAX:MIN;
            }
            //这里的res>=limit
            res=res*10-digit; //用减法
        }
        return positive?-res:res;
    }

    public boolean isDigit(char c){
        return c>='0' && c<='9';
    }
}
```

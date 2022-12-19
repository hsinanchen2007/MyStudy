The simple is the best.
```
class Solution {//原先的错误代码
    public int divide(int dividend, int divisor) {
        if(dividend/divisor>=Integer.MAX_VALUE||dividend/divisor<=Integer.MIN_VALUE){
            return Integer.MAX_VALUE;
        }else{
            return dividend/divisor;
        }
    }
}
```
![提交图片.png](https://pic.leetcode-cn.com/1a7c64dcc4f84663146923c97d0f070aa66de6c8b99b67a58594821505b559c4-%E6%8F%90%E4%BA%A4%E5%9B%BE%E7%89%87.png)
当我提交完错误的代码后，发现只有最后一个测试用例没有通过时，我意识到只要多加一个判断语句就行了

```
//执行时间1ms，100%击败，33.6MB
class Solution {//正确的代码
    public int divide(int dividend, int divisor) {
        if(dividend==Integer.MIN_VALUE&&divisor==1){
            return Integer.MIN_VALUE;
        }
        else if(dividend/divisor>=Integer.MAX_VALUE||dividend/divisor<=Integer.MIN_VALUE){
            return Integer.MAX_VALUE;
        }else{
            return dividend/divisor;
        }
    }
}
```


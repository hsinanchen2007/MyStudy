# Java正则表达式解法

## 整体思路
* `trim()`函数去除收尾空格
* 使用Java正则表达式匹配到合适的字符串
* 未匹配到则返回`0`
* 匹配到字符串后判断是否只是一个`+`或`-`，这种情况同样返回`0`（例如只输入`+`或`-`）
* 以上判断都通过则使用`Integer.parseInt()`将字符串转成数字，并根据异常判定是否溢出
* 溢出的返回值可以由字符串第一个字符是否是`-`来判定
## 测试结果

![image.png](https://pic.leetcode-cn.com/c17c2f6fd8f7ea3cccfd59584917741d61301acec8ceafa0f3471d6278a0d035-image.png)

## 存在的问题
- 对于正则匹配的结果处理显得冗余，还可以优化
- 异常判定的地方可能不够准确
```
import java.util.regex.Pattern;
import java.util.regex.Matcher;
class Solution {
    public int myAtoi(String str) {
        str=str.trim();
        
        String pattern="^[\\+\\-\\d]\\d*";//正则表达式，表示以正号或负号或数字开头，且后面是0个或多个数字
        Pattern p=Pattern.compile(pattern);
        Matcher m=p.matcher(str);
        
        String res="";
        if(m.find()){//能匹配到
            res=str.substring(m.start(),m.end());
        }else{//不能匹配到
            return 0;
        }
        
        //能匹配到但只有一个+-号，也返回0
        if(res.length()==1&&(res.charAt(0)=='+'||res.charAt(0)=='-')){
            return 0;
        }
        
        try{
            int r=Integer.parseInt(res);
            return r;
        }catch(Exception e){
            return res.charAt(0)=='-'?Integer.MIN_VALUE:Integer.MAX_VALUE;
        }
    }
}
```

#  符号表示
表示数值的字符串遵循两种模式：A：整数部分；B：小数部分，C：指数部分
1. A . B eC         比如 12.3e4
2. .B [eC]  可以不存在整数部分，只有小数部分
# 算法流程：（详细见代码）
1. 从整数部分A开始检查，因为整数前面可以有+-号，所以先检查正负号，再检查数字0-9
2. 第一步检查完后，指针都会停在第一个非数字地方（不算正负号）
3. 判断指针所指的符号：
    - 若是小数点'.' :  即检查小数部分，直接检查数字 
    - 若是符号'e'   :  即检查指数部分，先检查正负号，在检查数字
    - 若上述两者都不是： 就返回第1步整数检查的结果
```
class Solution {
    int  p=0; //字符数组指针
    public boolean isNumber(String s) {
        if(s == null) return false;     //1、鲁棒性判断
        s = s.trim();                   //去掉空格，用例中有"0 "
        if( s.length() == 0) return false;

        //2、转成字符数组
        char[] cs = s.toCharArray();

        //3、首先检查整数部分 A （先检查正负号，再检查数字）
        boolean isNum = sacnInteger(cs);
        //此时指针p的位置是第一个非数字字符 （除正负号）
        //下面进行判断指针位置是否是: 1）小数点. ； 2） e  ；3）都不是
        //4.1 如果是小数点，指针后移，直接调用检查小数部分数字的方法
        //4.2 如果是e, 指针后移，检查指数部分数字

        if(p<cs.length && cs[p]=='.'){
            ++p;
            isNum = scanUnsignedInteger(cs) || isNum ; 
            //这里用 或|| 是原因：整数A可以不存在，所以前面的检查结果可以为空
        }
        
        if(p<cs.length && cs[p]=='e'){
            ++p;
            isNum = isNum && sacnInteger(cs);
            //这里用 且&& 的原因：e前面必须存在，不然为false
        }
        return isNum && p == s.length();
    }   //===========================以下是检查两种检查数字方法====================================
        //检查数字0--9
    public boolean scanUnsignedInteger(char[] cs ){
        int  pre = p; //先保存当前的指针位置
        while( p!= cs.length && cs[p]>='0' && cs[p]<='9')  ++p; //遇到数字0-9就指针后移一位
        //返回结果：
        // 1）不存在数字，p == pre ,就返回false ； 
        // 2) 存在数字，指针后移停在第一个非数字的位置，p > pre ,返回true 
        return p > pre ; 
    }
        //检查正负号 +- 
    public  boolean sacnInteger(char[] cs){
        if(p< cs.length && ( cs[p] == '+' || cs[p] == '-'))
            ++p; // 如果有正负号，指针往后移动一位
        return scanUnsignedInteger(cs);  //接着去检查正常数字
    }
}
```

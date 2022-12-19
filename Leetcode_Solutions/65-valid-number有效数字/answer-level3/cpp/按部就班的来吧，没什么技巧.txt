# 题目分析
1. 这题我感觉是一种代码实现问题，考查考虑问题是否全面？
没有什么特别的算法思想，想清楚判定数字的流程，然后一路判断下来即可。但是要实现你原计划的流程，还是要好好打理一下自己的代码。
2. **字符特征** ： 
  2.1 可能包含”0~9“，”e“，”.“，“+”，“-”，” “。
  2.2  ”e” 允许出现的次数？还要考虑“e”后是否允许出现”." ， ”+“，”-“？是否允许作为开头结尾？前面是否一定要有数字？
  2.3  “." 允许出现的次数？ ”." 后是否允许出现 “e" , "+ " ,"- "？是否允许作为开头结尾 ？前面是否一定要有数字？
  2.4  ”+“ ，”-“，最多出现两次，一次在幂，一次在指数，且一定位于其他符号之前，且不能作为结尾
  2.5 ”0~9“ ，”0“是否允许在幂 或者 指数 或者 小数部分 的首部，是否允许”0“结尾的小数部分。
  2.6 ” “，只能作为开头结尾。
  2.7 整个数，必须要有数字出现。

3. **判断流程**
3.1 数前空格清除
3.2 首位判断+ - 号，然后进入幂部分/整数部分
3.3 正常判断数字，遇到 ”." 进入小数部分，“e” 进入指数部分，其余false。
3.4.1 小数部分，标记小数点已经用过，不能再出现，其余照常。
3.4.2 指数部分，检查e前是否有数字，”+“ ”-“可以再用，重置”+-“的标志位，小数点不能用了，小数点标志位置false，当然e也不能再用了。继续照常检查数字。
3.5 检查到” “，” “只能作为末尾出现，因此直接跳出主体循环，进入尾部判断环节。
3.6 数的结尾检查，不能是”e", "+ " "-" ，但可以是“ . ”。 
3.7尾部清洗，一路检查是否是“ ”，遇到个不是的则false。
3.8 检查全部通过，但它也要有数字才可能是数！return HasNum；


# 题解代码
```
class Solution {
public:
    bool isNumber(string s) 
    {   //0开头结尾 true
        //多个e  false
        //e左右两边要有数 
        //指数不能为小数
        int i=0;
        bool UsedSign=false;
        bool UsedCom=false;
        bool UsedExp=false;
        bool HasNum=false;
        //首部空格清除
        while(i<s.size())
        {
            if(s[i]!=' ')
                break;
            i++;
        }

        //首位判断符号位
        if(i<s.size() && (s[i]=='+' || s[i]=='-') )//符号
        {
            UsedSign=true;
            i++;
        }



        //主体判断
        for(;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {   
                HasNum=true;
                continue;
            }
            else if(s[i]=='+' || s[i]=='-')//主要用来判断指数的符号
            {
                if(UsedSign==false && s[i-1]=='e')
                {
                    UsedSign=true;
                    continue;
                }
                else
                    return false;
            }
            else if(s[i]=='.')//小数点
            {
                if(UsedCom==false)
                {
                    UsedCom=true;
                    continue;
                }
                else
                    return false;
            }
            else if(s[i]=='e')//指数符号
            {
                if(UsedExp==false && HasNum==true) //e前需有数字
                {
                    UsedExp=true;
                    UsedSign=false;//重置符号状态位,指数也可以带符号
                    UsedCom=true;//指数不能是小数
                    continue;
                    
                }
                else
                    return false;
            }
            else if(s[i]==' ') //尾部空格
                break;
            else
                return false;
        }

        if(s[i-1]=='e' ||s[i-1]=='+' || s[i-1]=='-')//e + -结尾 不行
            return false;

        while(i<s.size())//尾部空格清除
        {
            if(s[i]!=' ')
                return false;
            i++;
        }

        return HasNum;
    }
};
```

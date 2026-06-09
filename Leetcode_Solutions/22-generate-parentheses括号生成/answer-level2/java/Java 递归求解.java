**思路：n对括号包含2n个括号，第一个括号必定为左括号，在添加括号的中途，只需要处理如下情况即可：**
**变量定义：**
**n：剩余需匹配的括号数，初始为2n。**
**num：当前已生成字符串str中左括号大于有括号的个数**
(1)下一个可添加的括号为左括号或有括号，成立条件，当且仅当n的数目减去num还有剩余
解释：剩余匹配字符数n首先需要考虑括号配对情况，保证最终括号字符串左右括号数相等
(2)下一个可添加的括号为左括号，num为0时成立
解释：说明此时生成的字符串中左右括号已经匹配完成，下一个若添加右括号，则该右括号左边无左括号与其对应。此时只能添加左括号。
(3)下一个可添加的括号为右括号，n-num无剩余时成立
此时剩下的n均用于添加右括号以保证左右括号个数的匹配
```
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> list=new ArrayList<>();
        String str=new String("(");//初始字符必定是左括号
        find(list,str,2*n-1,1);   //只剩下2*n-1个符号需要排列位置
        return list;
    }
    /*
    *s为中途未完成的字符串
    *n为需要添加的字符个数
    *num为s中左括号大于右括号的个数
    */
    public void find(List list,String s,int n,int num)
    {
        if(n==0)
        {
            list.add(s);
            return;
        }
        if(n>=num+2&&num>=1)  //当剩余还需添加字符数大于左括号num+2且num>=1时，下一个添加的符号可以为左或者右括号
        {
            find(list,s+"(",n-1,num+1);
            find(list,s+")",n-1,num-1);
        }   
        else if(num==0)       //当num==0，说明此时左括号右括号数量相等，此时只能添加左括号
            find(list,s+"(",n-1,num+1);
        else//此步说明n<num+2,说明此时剩余添加的字符的个数除去还需匹配的num个右括号后还剩<2个（为0个，即n==num，剩下的全部用于添加右括号）
            find(list,s+")",n-1,num-1);
    }
}
```

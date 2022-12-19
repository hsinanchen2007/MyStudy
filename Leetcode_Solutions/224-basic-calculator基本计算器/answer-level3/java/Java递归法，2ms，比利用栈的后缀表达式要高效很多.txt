```
class Solution {
    char[] chs ;
    int len;
    int p=0;

    public int calculate(String s) {
        if(s==null||s.length()==0) return 0;
        chs = s.toCharArray();
        len=chs.length;

        return help();
    }
    //返回以p为开头的最长表达式的值,末尾如果多出右括号，则完成后p指向该右括号后面一位，否则指向表达式最后一位的下一位
    //保证调用的时候，p不会指向右括号,也不会超出范围,也不会后面没有元素
    private int help(){
        int ans=0;
        
        char sym='+';
        int num=0;
        while (p<len){
            char c=chs[p];
            if(c==' ') {//空格
                p++;
                continue;
            }
            if(c==')'){//右括号
                p++;
                break;
            }
            if(c=='+'||c=='-'){//符号
                if(sym=='+') ans+=num;
                else ans-=num;
                sym=c;
                num=0;
                p++;
            }else {//数字或左括号
                if(c=='('){//左括号
                    p++;
                    num=help();
                }else {//数字
                    num=num*10+c-'0';
                    p++;
                }
            }
        }
        if(sym=='+') ans+=num;
        else ans-=num;
        return ans;
    }
}
```

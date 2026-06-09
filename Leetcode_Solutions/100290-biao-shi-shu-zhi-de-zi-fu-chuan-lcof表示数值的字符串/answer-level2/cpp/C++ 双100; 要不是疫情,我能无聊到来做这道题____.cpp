来来来,给你们看一下奇葩测试用例
PS:这里我用 '~' 来代表空格了
`.       ->      false `      可以理解
`.1`      ->      true        ？？？
`~1`      ->      true        1前面有个空格!!!!
`1~`      ->      true        1后面有个空格!!!!
`.~`      ->      false       这个好歹正常一点了
`1~1`     ->      false       又是个陷阱....
`+~1`     ->      false       ？？？？？？
`+.1`     ->      true        我tm.......

行,踩了上面的坑,我就有一套体系了:
1、空格不能出现在串的中间
2、小数点前没有字符？补一个0上去就说得通了
2.5、最关键的三个符号：正负，小数，指数之间的关系
3、正负号之前不能有正负号，也不能有小数点
4、小数点之前不能有小数点，也不能有指数符
5、指数符之前不能有指数符
6、自己做的时候，尽量写一下注释，思路就清楚多了
```
class Solution {
public:
    bool pos_neg=1,power=1,point=1;     // 可用的符号：pos_neg是正负号,power是指数符,point是小数点
    bool isNumber(string s) {
        if(s.empty()) return 0;     // 啥?空的?还不快滚!
        else if(s[0]=='-' || s[0]=='+'){     // 正负号?没事,前面没有正负号和小数点就行
            if(pos_neg && s.length()>1 && ((s[1]>='0' && s[1]<='9') || s[1]=='.')){
                pos_neg=0;
                return isNumber(string(s,1));
            }
            else return 0;
        }
        else if(s[0]=='.'){     // 小数点?没事,前面没有小数点和指数符就行
            if(point && power && s.length()>1 && s[1]>='0' && s[1]<='9')
                return isNumber('0'+s);
            else return 0;
        }
        else if(s[0]==' '){     // 空格?没事,空格的尽头递归一遍就行
            int idx=0;
            while(idx<s.length() && s[idx]==' ')
                ++idx;
            return isNumber(string(s,idx));
        }
        else if(s[0]<'0'||s[0]>'9') // 啥?不是正负不是小数不是空格,还不是数字???还不快滚!
            return 0;
        for(int i=1;i<s.length();++i){
            if(s[i]>='0' && s[i]<='9');     // 数字?下一个
            else if(s[i]=='e'||s[i]=='E')  // 指数不允许后面有小数点和另一个指数,但允许正负号
                if(power){
                    power=0,pos_neg=1,point=0;
                    return isNumber(string(s,i+1));
                }
                else return 0;
            else if(s[i]=='.')     // 小数点不允许另一个小数点,而且小数点前面不能有指数
                if(point && power)
                    point=0;
                else return 0;
            else if(s[i]==' '){     // 空格不允许出现在串中
                while(i<s.length() && s[i]==' ') ++i;
                return i==s.length();
            }
            else return 0;
        }
        return 1;
    }
};
```

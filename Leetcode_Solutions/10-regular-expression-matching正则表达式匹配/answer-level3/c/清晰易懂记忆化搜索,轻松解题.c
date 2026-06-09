#### 记忆化搜索
动态规划的题,尤其是这种按照一定步骤的模拟题,如果实在推不出动态转移方程,便可以使用记忆化搜索,按照题意分析情况,根据情况模拟,写出递归,但递归往往因重复递归而超时这就需要记忆化,省去重复步骤,而动态规划就是在记忆化搜索的基础上将其"迭代化"

正则表达式匹配无非三种情况:
1.".*"可匹配所有
2."字母+*"可匹配所有该字母
3.两字母相同匹配

注意
1.记住顺序不能颠倒


```
int memo[100][100];
bool dfs(char *s,char *p,int s_index,int p_index)
{
    if(s[s_index]=='\0'&&p[p_index]=='\0')return true;//如果都遍历到最后说明匹配成功
    if(p[p_index]=='\0')return false;//如果p字符串匹配到最后,而s没有,则匹配不成功
    if(memo[s_index][p_index]!=-1)return memo[s_index][p_index];//记忆化,判断当前位置是否被搜过,是子直接返回当前结果,省去重复步骤
    bool flag=false;//初始标记
    if(p[p_index]=='.')//首先判断该位置是否是点
    {
        if(p[p_index+1]=='*')//然后判断下一个是否是*,如果是*,则可以匹配s中的任意个不同字符
        {
            for(int i=s_index;i<=strlen(s);i++)//遍历s当前位置到末尾,看是否能匹配成功
            {
                flag=dfs(s,p,i,p_index+2);//p是.*代替s,所以加2
                if(flag==true)//如果能匹配直接停止
                    break;
            }
        }
        else if(s[s_index]!='\0')//如果下一个不是*,一个.只能匹配一个字符
        {
            flag=dfs(s,p,s_index+1,p_index+1);//p是.代替s一个字符,所以各加1
        }
    }
    else if(p[p_index+1]=='*')//如果当前位置是字母,下一个是*,*可以匹配0个或多个s中与当前字母一样的字符
    {
        flag=dfs(s,p,s_index,p_index+2);//当匹配0个的情况,p中字母+*代替s中0个字符
        if(flag==false)//如果匹配不成功
        {
            for(int i=s_index;i<strlen(s);i++)//遍历s当前位置到末尾,看是否能匹配成功
            {
                if(s[i]==p[p_index])//即p中字母+*是否等价于s当前位置的字母,是则进行下一位置的匹配
                    flag=dfs(s,p,i+1,p_index+2);
                else//否则停止
                    break;
                if(flag==true)//如果匹配成功停止
                    break;
            }
        }
    }
    else if(s[s_index]==p[p_index])//在以上情况不满足的情况下,如果两字符相等,则遍历下一位置
    {
        flag=dfs(s,p,s_index+1,p_index+1);
    }
    //其他情况皆为false
    memo[s_index][p_index]=flag;//记忆化存储
    return flag;
}
bool isMatch(char * s, char * p){
    memset(memo,-1,sizeof(memo));//设-1为未访问过
    return dfs(s,p,0,0);
}
/*
"mississippi"
"mis*is*p*."
"ab"
".*"
""
".*"
"a"
".*..a*"
"aab"
"c*a*b"
*/
```
找到所有括号的组合方式看起来比较复杂。
所以我们可以尝试换个思路：**如果“(”对应数字1，“)”对应数字-1呢？**
通过观察我们可以发现这样一个规律：
**凡是有效的括号组合，转化成数字，任意前n项和都不小于0！**
比如：“（）（）（）”
前1位：1>=0;前2位：1+(-1)=0>=0;前3位：1+(-1)+1=1>=0;
......以此类推，前n位数字和均大于等于0.
又比如：“（（（）））”
前3位：1+1+1=3>=0;前4位：1+1+1+(-1)=2>=0;前5位：1+1+1+(-1)+(-1)=1>=0;
......依然满足规律。
至此，我们就能想到这样一个思路：
**1.目标为n时，可以转化为n个-1和n个1
2.求这串数字的所有排列
3.满足以上规律的就是有效的括号组合
4.最后一步再将数字组合转化成括号组合**

整个过程需要一些小的工具：
**1.求全排列的函数：next_permutation
2.数字转化成括号：容器map**

以下是代码：
```
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        if(n == 0){return result;}
        vector<vector<int>> mid;
        vector<int> temp;
        for(int i = 0 ; i < n ; i ++)
        {
            temp.push_back(-1); //先放所有的-1
        }
        for(int i = 0 ; i < n ; i ++)
        {
            temp.push_back(1);  //再放所有的+1（这样的原因是因为全排列需要从小到大的顺序）
        }
        while(next_permutation(temp.begin(),temp.end()))    //求全排列
        {
            int target = 0;
            int judg = 1;
            for(auto i:temp)
            {
                target+=i;
                if(target < 0)
                {
                    judg = 0;break; //是否满足前n项之和不小于0
                }
            }
            if(judg == 1){mid.push_back(temp);}
        }
        map<int,string> invert;
        invert.insert(map<int,string>::value_type(1,"("));  //1对应左括号
        invert.insert(map<int,string>::value_type(-1,")")); //-1对应右括号
        for(auto i:mid)
        {
            string s;
            for(auto j:i)
            {
                s += invert[j]; //数字组合转化成字符串
            }
            result.push_back(s);
        }
        return result;
    }
};
```




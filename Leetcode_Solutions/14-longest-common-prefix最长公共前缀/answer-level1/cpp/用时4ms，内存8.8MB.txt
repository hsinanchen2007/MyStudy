# 熟练用一些c++的函数做起来会很简单
比较适合小白理解，代码有注释，很容易看懂的。

# c++代码如下：
```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int i=0,j;
        bool status=true;//设置status为了遍历时跳出循环
        if(strs.size()==0||strs[0]=="")//向量中没有元素或者向量中仅有一个空字符串
            return ans;
        while(1)
        {
            for(auto &x:strs)//遍历str中的每个字符串
            {   
                if(x[i]!=strs[0][i])
                {
                    status=false;
                    break;
                }
            }
            if(status==false||i+1>strs[0].size())//当出现有一个字符不符合情况或者i=strs[0].size()-1时（已经遍历到最后了）
                break;
            else
                i++;
        }
        for(j=0;j<i;j++)
        {
            string s(1,strs[0][j]);//将字符变成字符串方便合成
            ans+=s;
        }
        //这一段可以直接用if(i>0)ans=str[0].substr(0,i);来代替
        return ans;
    }
};
```

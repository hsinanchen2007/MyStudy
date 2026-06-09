![image.png](https://pic.leetcode-cn.com/c873e2616cffdb57adea918783f23b9c4a0b26ae68263e838f585f6a05b308f9-image.png)
```
class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int> s1;//专门存括号的，用来检查括号的准确性。
        //栈中存放的是非法的括号对应的id
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a'&&s[i]<='z') continue;
            else if(!s1.empty()&&s[s1.top()]=='('&&s[i]==')')
            {
                s1.pop();
            }
            else s1.push(i);
        }
        //for循环遍历之后的字符串，栈中剩下的就是非法字符
        //栈中下面是小的id,上面的是大的id
        //我们在输出最后的合法字符串，无非就是想避开这些栈
        //因为我们是从左到右，也就是id从小到大的方向输出
        
        //因此也需要将栈反转
        stack<int> s2;
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        //输出结果
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if(!s2.empty()&&i==s2.top())
            {
                s2.pop();
                continue;
            }
            else res+=s[i];
        }
        return res;

    }
};
```

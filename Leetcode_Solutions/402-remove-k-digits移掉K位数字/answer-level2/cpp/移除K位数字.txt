### 解题思路
贪心实现

思想：
要使删除k位数后该数最小
每次删除操作都要保证高位最小，如果数据出现下降趋势，(s[i]<s[i+1])
s[i]要删除，不然s[i]在较高的位置，不能保证最后是最小的数
-------------------------------------------------------------
实现：
使用栈保留 已经确定的高位数据
遍历S： 0-s.length()
   如果栈不空 且 栈顶元素较大 且 k>0
    持续退栈
   否则 元素入栈
最后，考虑其他情况 元素本来就是降序排列，即数据都在栈内但k>0
  持续退栈直到k==0
栈内即为答案
### 代码

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        vector<int> st;
        for(int i=0;i<num.length();i++)
        {
            int n=num[i]-'0';
            //退栈 栈不空&&k>0&&st.top>num[i]
            while(!st.empty()&&k>0&&st[st.size()-1]>n)
            {
                st.pop_back();
                k--;
            }
            if(n!=0||st.size()!=0) st.push_back(n);
        }
        while(k>0&&st.size()!=0)
        {
            st.pop_back();
            k--;
        }
        string res="";
        for(int i=0;i<st.size();i++)
        {
            res+=st[i]+'0';
        }
        if(num==""||st.size()==0) res="0";
        return res;
    }
};
```
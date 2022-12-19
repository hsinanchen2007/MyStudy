### 解题思路
![TIM图片20200408132510.png](https://pic.leetcode-cn.com/8c4578c0240fe1381a56ad045ae444e85e80126d8ca98268711234d496c904ce-TIM%E5%9B%BE%E7%89%8720200408132510.png)


### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char>st;
        int num=0;
        for(int i=0;i<s.size();i++)
        {
            if((st.size()==1&&s[i]=='R'&&st.top()=='L')||(st.size()==1&&s[i]=='L'&&st.top()=='R'))
            {
                st.pop();
                num++;
            }
            else if(st.size()>1&& ((s[i]=='R'&&st.top()=='L')||(s[i]=='L'&&st.top()=='R')))
            {
                st.pop();
                if(st.empty())num++;
            }
            else st.push(s[i]);
        }
        return num;
    }
};
```
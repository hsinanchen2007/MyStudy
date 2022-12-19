容易发现满足条件的字符串"#"号比数字多一个，且最后一个有效字符为"#"，排除之后利用栈遍历字符串，数字进，井号出，判断是否栈空即得。
ps：有个疑问，我之前在C++11里用vector可以直接利用std::stoi()函数将字符串转数字，但在这个leetcode里总是需要一个构造临时的string才能使用stoi()函数
有大佬能解答一下吗，是C++版本的问题还是别的什么
```
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> s;
        int p=preorder.size();
        if(preorder[p-1]!='#') return false;
        for(int i=0;i<p-1;i++)
        {
            if(preorder[i]!='#'&&preorder[i]!=',')
            {
                string tmp="";
                while(preorder[i]!=',')
                {
                    tmp.push_back(preorder[i]);
                    i++;
                }
                s.push(stoi(tmp));
            }
            else
            {
                if(preorder[i]==',')  continue;
                else
                {
                    if(s.empty()) return false;
                    s.pop();
                }  
            }
        }
        if(!s.empty()) return false;
        return true;
    }
};
```

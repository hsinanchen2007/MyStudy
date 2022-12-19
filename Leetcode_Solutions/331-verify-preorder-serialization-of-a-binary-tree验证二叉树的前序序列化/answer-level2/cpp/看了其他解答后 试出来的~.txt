看了大佬的解答之后，发现去掉原字符串的最后一个"#"，再他们依次入栈，碰到"#"就出栈，遍历到最后，如果栈为空就说明这是一个前序的二叉树。
当原字符串长度为1的时候需要单独判断。
```
class Solution {
public:
    //把字符串按照逗号分割，存储到vector中
    void SplitString(const string& s, vector<string>& v, const string& c)
    {
        string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
          
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
    }
    
    bool isValidSerialization(string preorder) {
        if(preorder.length()==1) 
        {
            if(preorder[0]=='#') 
                return true;
            else
                return false;
        }
        stack<string> s;
        vector<string> v;
        string str = preorder.substr(0,preorder.length()-1);
        SplitString(str,v,",");
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]=="#")
            {
                if(!s.empty())
                    s.pop();
                else
                    return false;
            }
            else
                s.push(v[i]);
        }
        return s.empty();
    }
};
```

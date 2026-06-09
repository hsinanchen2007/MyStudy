### 解题思路
利用和编译器相似的原理，将字符串分解成树结构，再自底向上获取字符串
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Tree
{
    public:
    vector<Tree> vec;
    int repeat;
    string str;
    Tree(string s,int rep)
    {
        repeat=rep;
        cout<<s<<" "<<rep<<" "<<s.size()<<endl;
        for(int i=0;i<s.size();)
        {
            if(s[i]>=48&&s[i]<=57)
            {
                string buff;
                int repd;
                string reps;
                while(s[i]!='[')
                {
                    reps.push_back(s[i]);
                    ++i;
                }
                repd=atoi(reps.c_str());
                int leftcount=1;
                ++i;
                for(;leftcount!=0;++i)
                {
                    if(s[i]=='[')
                    {
                        ++leftcount;
                        buff.push_back(s[i]);
                    }
                    else if(s[i]==']')
                    {
                        --leftcount;
                        if(leftcount!=0)
                        {
                            buff.push_back(s[i]);
                        }
                    }
                    else
                    {
                        buff.push_back(s[i]);
                    }
                }
                vec.push_back(Tree(buff,repd));
                str.push_back((char)(-vec.size()));
            }
            else
            {
                str.push_back(s[i]);
                ++i;
            }
        }
    }
    string getStr()
    {
        string ret;
        for(int i=0;i<str.size();++i)
        {
            if((int)str[i]>=0)
            {
                ret.push_back(str[i]);
            }
            else
            {
                ret.append(vec[(-(int)(str[i]))-1].getStr());
            }
        }
        string retb=ret;
        for(int i=0;i<repeat-1;++i)
        {
            ret.append(retb);
        }
        return ret;
    }
};

class Solution {
public:
    string decodeString(string s) {
        Tree tr(s,1);
        return tr.getStr();
    }
};
```
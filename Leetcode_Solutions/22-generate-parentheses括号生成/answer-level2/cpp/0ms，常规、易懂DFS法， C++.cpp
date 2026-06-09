欢迎交流，感谢批评指正

### 代码

```cpp
class Solution {
public:
    void DFS(vector<string>& v_str,string& str, int n, int L, int R)   //L表示左左括号数
    {
        if(L==n)    //左括号满了
        {
            if(R==n) v_str.push_back(str);
            else    //若此时右括号没满，则直接后面排满右括号
            {
                for(int k=R; k<n; k++)
                {
                    str.append(")");
                }
                v_str.push_back(str);
            }
        } 
        else       //左括号没满
        {
            if(L==R)    //一旦左右括号相等，立马添加左括号！ 这句很重要
            {
                str.append("(");
                L++;
                DFS(v_str, str, n, L, R);
            }
            else
            {
                for(int i=0; i<2; i++)
                {
                    if(i==0 ) 
                    {
                        str.append("(");    //先加左括号
                        L++;
                        DFS(v_str, str, n, L, R);
                        L--;                //回溯
                        str.erase(L+R);
                    }
                    else
                    {
                        str.append(")");    //回溯后，改为添加右括号
                        R++;
                        DFS(v_str, str, n, L, R);
                        //R--;    //一开始加了这段语句，但仔细思考if(L==R) 这段语句后，其实可省略此句
                        //str.erase(L+R);
                    } 
                }
            }
        }     
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v_str;
        string str;
        DFS(v_str, str, n, 0, 0);
        return v_str;
    }
};
```
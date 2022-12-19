### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        string temp;
        backtracking(n,0,0,temp);
        return res;
    }
    void backtracking(int n,int left,int right,string &temp)
    {
        if(left>n||right>left||right>n)//剪枝，右括号数不能多于左括号数
            return;
        else if(left==n&&right==n)//当所有括号都写入后
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<2;i++)//每个位置有两种可能
        {
            if(i==0)//第一种是放左括号
            {    
                left++;
                temp.push_back('(');
            }
            else//第二种是放右括号
            {    
                right++;
                temp.push_back(')');
            }
            backtracking(n,left,right,temp);//回溯
            if(i==0)//回复之前的状态
            {    
                left--;
                temp.pop_back();
            }
            else
            {    
                right--;
                temp.pop_back();
            }
        }
    }
};
```
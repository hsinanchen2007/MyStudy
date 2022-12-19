### 解题思路
递归搜索

### 代码

```cpp
class Solution {
private:
    vector<string> vec;
public:
    Solution()
    {
        vec.clear();
    }
    void dfs(string& now,int left,int right,int& n)
    {
        //对于每一个位置，当前位置可能存放左括号和右括号两种情况，针对每种情况分类讨论
        //存放左括号的时候，要求当前左括号数量不能超过n，存放右括号的时候，要求此时右括号数量要小于等于左括号，否则不能匹配
        if(now.size()==2*n) {
            vec.push_back(now);
            return;
        }
        if(left+1<=n) {
            now += '(';
            dfs(now,left+1,right,n);
            now = now.substr(0,now.size()-1);
        }
        if(right+1<=left) {
            now += ')';
            dfs(now,left,right+1,n);
            now = now.substr(0,now.size()-1);
        }
    }
    //给出n对括号完全合法的所有配对
    vector<string> generateParenthesis(int n) {
        if(n<=0) return vec;
        if(n==1) {
            vec.push_back("()");
            return vec;
        }
        //递归构造
        string now = "";
        dfs(now,0,0,n);
        return vec;
    }   
};
```
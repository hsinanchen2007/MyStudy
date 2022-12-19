### 解题思路
全排列问题一般都会用到深度遍历优先（或者说是回溯法），递归调用流程非常标准，不过是加了左右括号的限制，会导致一些配对出现的问题，以及右括号不能比左括号多，所以是有限制的全排列。在这里主要是利用了left>0和right>left的限制进行剪枝。
注意代码里不能用注释掉的部分替换+"(或)",否则会多打几个左括号，原因是因为在left>0判断完后，会继续执行right>left的判断，此时如果用append就已经多加了一个“（“ ，而如果写在函数里面就不会产生这个问题

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n<=0)
            return {};
        dfs(n,n,"");
        return ans_str; 
    }

private:
    vector<string> ans_str;    
    void dfs(int left,int right,string cur_str) {
        if(left==0 && right==0){
            ans_str.emplace_back(cur_str);
            return;
        }
        if(left>0){
            //cur_str.append("(");            
            dfs(left-1,right,cur_str+"(");
        }
        if(right>left){
            //cur_str.append(")");            
            dfs(left,right-1,cur_str+")");
        }
    }
};
```
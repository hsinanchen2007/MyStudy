### 解题思路
		(
((				()
  (()     ()(     
	 (())   ()()
递归：先添加左括号，再添加有括号
减枝：右括号大于左括号，左括号大于n
添加路径：左括号等于右括号等于n
### 代码

```cpp
class Solution {
public:
void dfs(vector<string>& vec, int n, int left, int right, string path){
    if(left > n || right > n || left < right)
        return;
    
    if(n == left && n == right){
        vec.push_back(path);
        return;
    }
        
    
    dfs(vec, n, left + 1, right, path + "(");
    dfs(vec, n, left, right + 1, path + ")");
}

vector<string> generateParenthesis(int n) {
    vector<string> vec;
    dfs(vec, n, 0, 0, "");
    return vec;
}
};
```
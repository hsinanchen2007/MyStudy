### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }

    void dfs(vector<string> & res, string  str,int left,int right)
    {
        if(left == 0 && right == 0)             res.push_back(str); 
        if(left > 0)          dfs(res, str + "(", left - 1, right);
        if(right > left)      dfs(res, str + ")", left, right - 1);
    }
};
```
  
  

看见一个图片很直观，这里直接放出来了        图片来源:ChineseKawhi

![QQ图片20200409115535.png](https://pic.leetcode-cn.com/1f18f8cae809764acdeca72f8049a8fca15e1c462643273063bb19bc2f166512-QQ%E5%9B%BE%E7%89%8720200409115535.png)


首先观察 
* 一对括号只有一种()
* 两对括号有2种()(), (())   # 在一对的基础上，所有的空白位置左边、中间、右边插入一对括号，去重
* 三对括号有5种"((()))",  "(()())",  "(())()",  "()(())",  "()()()" # 在两对的基础上，每一组括号对的每一个位置插入一对括号，并去重
* 随意找到n对括号数的每个可插入的位置插入一个括号，去重即为n+1对括号数的解。

正确性
- 由于n-1对括号满足条件，在任意位置插入一对括号也是满足条件的；
- 也不会漏解，因为n对可解括号一定有一对括号是连续的，去掉后一定在n-1对正确括号中。

具体做法：
1. 保留两个集合pre，now；
2. 每次遍历pre中的每个字符串
3. 尝试在每一个字符串的每个位置插入一对括号，并将结果加入now集合
4. pre = now

``` python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n==0:
            return []
        
        pre = set({'()',})
        
        for i in range(n-1):
            now = set()
            for st in pre:
                n = len(st)
                for index in range(n):
                    now.add(st[0:index]+'()'+st[index:n])
            pre = now
        return list(pre)
```

顺带分享下C++版本的递归，仿powcai的写法。
``` C++
class Solution {
public:
    void helper(int left, int right, string tmp, vector<string> &result) {
        if (left == 0 && right == 0) {
            result.push_back(tmp);
            return;
        }
        
        if (left>right || left<0 || right<0)  //左括号用的比右括号少
            return ;
      
        helper(left-1, right, tmp+'(', result);
        helper(left, right-1, tmp+')', result);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        helper(n,n, "", result);
        return result;
    }
};
```



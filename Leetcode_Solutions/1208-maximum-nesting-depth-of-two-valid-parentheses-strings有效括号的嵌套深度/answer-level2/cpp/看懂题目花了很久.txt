### 解题思路
这道题目其实类似于栈的思想。
我之前还想复杂了。
其实，不需要实现栈。只需要记录括号的顺序即可。
我们看到一共就两个子序列。
所以，我们需要满足的就是不把相邻的“（”放在一起，就可以了。
那么就可以按照奇偶的操作性质来做这道题目了。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //找嵌套程度最小
        //找到嵌套的位置。
        vector<int> res;
        int depth = 0;
        for(int i=0;i<seq.size();i++){
            if(seq[i] == '('){
                depth++;
                res.push_back(depth % 2);
            }else{
                res.push_back(depth % 2);
                depth--;
            }
        }
        return res;
    }
};
```
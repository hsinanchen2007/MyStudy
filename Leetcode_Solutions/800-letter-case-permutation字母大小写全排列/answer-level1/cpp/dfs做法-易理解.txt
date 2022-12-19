### 解题思路
遍历一个字符串的过程其实可以看做遍历一棵树
以“a1b2”为例，头结点为a由于是字母，往下延伸两个子树“a”和“A”
然后分别对”a“和“A”继续操作，由于1为数字，故只进行单个孩子延伸变成“a1”和“A1”
依次类推，到了叶子结点，便是四种情况，这和求一棵树的所有从根到叶子结点的路径很像，这里的叶子结点也相当于路径，
不同的是，在这里的结点时边建立，边遍历（实际遍历的是字符串）的。
### 代码

```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        dfs("", 0, ans, S);
        return ans;
    }
    void dfs(string str, int index, vector<string>& ans, string S) {
        //叶结点为目的地
        if(index == S.length()) {
            ans.push_back(str);
            return;
        }
        if(S[index] >= '0' && S[index] <= '9') { //如果当前为数字
            dfs(str + S[index], index + 1, ans, S);
        } else { //如果当前是字母
            dfs(str + S[index], index + 1, ans, S);
            if(S[index] >= 'A' && S[index] <= 'Z') {
                //走两边，这是另一边，如果是大写，换小写
                char a = S[index] - 'A' + 'a';
                dfs(str + a, index + 1, ans, S);
            } else { //小写
                char a = S[index] - 'a' + 'A';
                dfs(str + a, index + 1, ans, S);
            }
        }

    }
};
```
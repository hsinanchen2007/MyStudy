### 解题思路
1. 回溯法：回溯法（探索与回溯法）是一种选优搜索法，又称为试探法，按选优条件向前搜索，以达到目标。 但当探索到某一步时，发现原先选择并不优或达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为回溯法，而满足回溯条件的某个状态的点称为“回溯点”。
2. 使用引用传递可以减少不必要的对象创建，节省内存
3. vector的push_back会进行拷贝
4. string的push_back方法在字符串末尾添加一个字符
5. string的pop_back方法在字符串末尾删除一个字符
6. 使用回溯法可以保证在每个时间点prefix字符串不会同时被使用，所以可以使用引用传递
7. 拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。
8. Line( const Line &obj);      // 拷贝构造函数
9. Line line2 = line1; // 这里调用了拷贝构造函数

### 代码

```cpp
class Solution {
public:
    void generateParenthesis(string& prefix, int current_has_left_count, int total_has_left_count, int n, vector<string>& ans) {
        if (total_has_left_count == n && current_has_left_count == 0) {
            ans.push_back(prefix);
            return;
        }
        if (total_has_left_count < n) {
            prefix.push_back('(');
            generateParenthesis(prefix, current_has_left_count + 1, total_has_left_count + 1, n, ans);
            prefix.pop_back();
        }
        if (current_has_left_count > 0) {
            prefix.push_back(')');
            generateParenthesis(prefix, current_has_left_count - 1, total_has_left_count, n, ans);
            prefix.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string prefix;
        generateParenthesis(prefix, 0, 0, n, ans);

        return ans;
    }
};
```
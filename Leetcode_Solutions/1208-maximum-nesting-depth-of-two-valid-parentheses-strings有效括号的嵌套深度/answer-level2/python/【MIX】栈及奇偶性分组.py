### 解题思路
1. 括号压栈, 如果出现()匹配则出栈
2. 记录括号的嵌套深度, 元素所在栈的高度
3. 嵌套深度相同的括号编为一组

### 代码

```c++ []
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // 1.括号压栈, 如果出现()匹配则出栈
        // 2.记录括号的嵌套深度, 元素所在栈的高度
        // 3.嵌套深度相同的括号编为一组
        int N = seq.size();
        stack<char> st;
        vector<int> res(N, 0);
        for(int i=0; i<N; ++i){
            if(seq[i] == '('){
                st.push(seq[i]);
                res[i] = (st.size()&0x01);
            }
            else{
                res[i] = (st.size()&0x01);
                st.pop();
            }
        }
        return res;
    }
};
```
```java []
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int N = seq.length();
        char[] s = seq.toCharArray();
        int []res = new int[N];
        Stack<Character> st = new Stack<>();
        for(int i=0; i<N; ++i){
            if(s[i] == '('){
                st.push(s[i]);
                res[i] = (st.size()&0x01);
            }
            else{
                res[i] = (st.size()&0x01);
                st.pop();
            }
        }

        return res;
    }
}
```
```python []
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        res = []
        st = []
        for s in seq:
            if s == '(':
                st.append(s)
                res.append(len(st)&0x01)
            else:
                res.append(len(st)&0x01)
                st.pop(-1)

        return res
```
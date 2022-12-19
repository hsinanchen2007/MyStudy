### 解题思路
1. 对非空字符判断并入栈, 出栈后即逆序
2. `strip()` `trim()`, `reversed()`, `join()`等API的调用
### 代码

```c++ []
class Solution {
public:
    string reverseWords(string s) {
        // 空间复杂度为O(L)的解法
        if(s.size()==0) return s;
        string res;
        string word;
        for(int i=0; i<s.size(); ++i){
            if(s[i] != ' '){
                word+=s[i];
            }
            else{
                if(word.empty()) continue;
                else{
                    st.push(word);
                    word.clear();
                }
            }
        }
        // 最后一个单词入栈
        if(!word.empty()) st.push(word);

        while(!st.empty()){
            res += st.top();
            res += " ";
            st.pop();
        }
        if(!res.empty()) res.pop_back(); // 去除最后一个空格
        return res;
    }
private:
    stack<string> st;
};
```
```python []
class Solution:
    def reverseWords(self, s: str) -> str:
        # split()根据空格拆分单词
        # reversed()逆序单词
        # join()拼接单词
        return ' '.join(reversed(s.split()))
```
```java []
class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        List<String> wordLst = Arrays.asList(s.split("\\s+"));
        Collections.reverse(wordLst);
        return String.join(" ", wordLst);
    }
}
```

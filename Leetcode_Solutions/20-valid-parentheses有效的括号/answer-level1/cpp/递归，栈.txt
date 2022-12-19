### 解题思路
第一个想到的思路是用递归，  注意要用一个变量来记录相同的字符个数，  如({()}[])  ()里嵌套了()不能把里面字符的结束当做外面字符的结束。


第二个是看到评论里说用栈。。   真的很巧妙，  怪不得是简单题。。。

### 代码

```cpp
class Solution {
public:
    // 执行用时 :1708 ms, 在所有 C++ 提交中击败了10.19% 的用户
    // 内存消耗 :6.9 MB, 在所有 C++ 提交中击败了100.00%的用户
    unordered_map<char,char> map{{'(',')'},{'[',']'},{'{','}'}};
    bool isValid(string s) {
        if(s.size()<1) return true;
        if(s.size()&1) return false;
        return isValidCore(s, 0, s.size()-1);
    }
    bool isValidCore(string& s, int start, int end){
        if(start>end) return true;
        int mid = start+1;
        int count1 = 0;   //记录相同的字符。
        while(mid<=end){
            if(s[start]==s[mid]){
                ++count1;
            }
            if(map[s[start]]==s[mid]){
                --count1;
                if(count1==-1){
                    return isValidCore(s, start+1,mid-1)&&isValidCore(s, mid+1, end);
                }
            }
            ++mid;
        }
        return false;
    }


    // 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗 :6.3 MB, 在所有 C++ 提交中击败了100.00%的用户
    unordered_map<char,char> map{{'(',')'},{'[',']'},{'{','}'}};
    bool isValid(string s) {
        if(s.size()==0) return true;
        if(s.size()&1) return false;
        stack<char> sc;
        int i = 0;
        while(i<s.size()){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                sc.push(s[i]);
            }
            else if(!sc.empty()&&s[i]==map[sc.top()])
                sc.pop();
            ++i;
        }
        if(sc.empty()) return true;
        return false;
    }

};
```
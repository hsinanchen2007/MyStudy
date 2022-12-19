1. 遍历字符串每一个字符，用栈保存最右字符与出现次数；
2. 若栈顶字符出现了 $k$ 次，弹出栈顶元素（相当于删除），若栈为空，或者并没有出现连续 $k$ 个字符，压入当前字符并记次数为 $1$；
3. 因为结果要记录删除后剩余的字符串，因此用 `vector` 数组来实现栈的功能（`back()` 访问栈顶元素，`push_back` 与 `pop_back` 实现压栈与出栈）；
4. 进行「删除操作」后，遍历 `vector` 数组，加上 `len` 个每个当前元素，其中 `len` 为记录的连续重复出现的个数。
```cpp [-C++]
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int> > st;
        for(auto& i : s){
            if(!st.empty() && st.back().first == i){
                if(++st.back().second == k)st.pop_back();
            } 
            else{
                st.push_back(make_pair(i,1));
            }
        }
        string res;
        for(auto& i : st){
            int l = i.second;
            while(l--)
                res += i.first;
        }
        return res;
    }
};
```

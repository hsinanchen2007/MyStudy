### 解题思路
1、build过程，用set容器insert函数
2、search过程，遍历字典，字符长度不同时continue;字符完全相同时continue；再用一个bool函数判断两个字符串对应位不同的数量有多少，若只有一位不同则满足条件。

### 代码

```cpp
class MagicDictionary {
public:
    set<string> st;
    /** Initialize your data structure here. */
    MagicDictionary() {//构造函数

    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i = 0; i < dict.size(); i++){
            st.insert(dict[i]);
        }
    }
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if(st.empty()) return false;
        for(auto str : st){
            if(str.size() != word.size()) continue;
            if(str == word) continue;
            if(is_changed(str, word)) return true;
        }
        return false;
    }
    
    bool is_changed(string str1, string str2){
        int length = str1.size();
        int cnt = 0;
        for(int i = 0; i < length; i++){
            if(str1[i] != str2[i]) cnt++;
        }
        if(cnt == 1) return true;
        else return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
```
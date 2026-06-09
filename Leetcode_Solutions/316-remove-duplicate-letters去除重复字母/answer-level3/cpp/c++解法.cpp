1.遍历字符串，用map记录字符出现的最后位置；
2.第二次遍历字符串时，维护一个记录结果的栈，用vector实现；
3.维护一个map记录当前字符是否在栈里（就不需要遍历数组，看是否存在），当在栈里时，继续遍历，不在转4；
4.当栈不为空且字典序比当前元素大时，并且栈顶字符在原字符串中出现的位置比当前下标i更大，说明栈顶字符会在之后出现。弹出栈顶元素，并将栈顶元素是否在栈中的记录抹除；
5.压栈当前字符；
6.结果为vector数组中的字符顺序。
```
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mp;
        unordered_map<char, int> in_st;
        for(int i = 0; i < s.size(); ++i)
            mp[s[i]] = i;//记录某个字符出现的最后位置
        vector<char> st;//记录结果的栈
        for(int i = 0; i < s.size(); ++i){
            if(in_st[s[i]])continue;//栈中有当前遍历的字符
            while(st.size() && s[i] < st.back() && mp[st.back()] > i){
            //栈顶元素会在之后的位置出现
                --in_st[st.back()];
                st.pop_back();
            //出栈并抹除记录
            }
            st.push_back(s[i]);
            ++in_st[s[i]];
        //压栈，并记录出现过
        }
        string res;
        for(auto& i : st)res += i;    
        return res;
    }
};
```

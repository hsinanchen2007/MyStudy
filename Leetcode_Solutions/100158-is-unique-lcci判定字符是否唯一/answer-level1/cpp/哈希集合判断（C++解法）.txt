```
class Solution {
public:
    bool isUnique(string astr) {
        int len = astr.size();
        if(len == 0)
            return true;
        unordered_set<char> st;
        for(int i=0;i<len;i++){
            if(st.find(astr[i]) != st.end())
                return false;
            st.insert(astr[i]);
        }
        return true;
    }
};
```

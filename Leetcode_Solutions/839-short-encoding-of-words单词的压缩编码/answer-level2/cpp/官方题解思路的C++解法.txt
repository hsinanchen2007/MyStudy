class Solution {
public:
int minimumLengthEncoding(vector<string>& words) {
    if (words.size() == 1) {
        return words[0].size() + 1;
    }
    set <string> st;
    for (string word : words) {
        st.insert(word);
    }
    
    for (string word : words) {
        for (int k = 1; k < word.size(); k++) {
            st.erase(word.substr(k));
        }
    }
    
    int ans = 0;
    for (string word : st) {
        ans += (word.size() + 1);
    }
    
    return ans;
    }
};
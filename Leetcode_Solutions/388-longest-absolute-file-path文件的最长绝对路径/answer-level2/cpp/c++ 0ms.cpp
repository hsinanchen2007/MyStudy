```cpp
class Solution {
public:
    int lengthLongestPath(string input) {
        size_t p = 0;
        const auto pop_path = [&p, &input](int& depth, string& str) bool {
            depth = 0;
            str = "";
            if (p >= input.length()) return false;

            while (p < input.length() && input[p] == '\t') { depth++; p++;}
            while (p < input.length() && input[p] != '\n') { str.push_back(input[p++]); }
            p++;

            return true;
        };

        const auto is_file = [](const string& s) {
            for (auto c: s) {
                if (c == '.') return true;
            }

            return false;
        };

        stack<int> st;
        int maxlen = 0;
        while (true) {
            int depth = 0;
            string path;
            if (!pop_path(depth, path)) break; // no path avaliable

            while (st.size() > depth) st.pop(); // pop to specify depth

            int len = (st.empty() ? 0 : (st.top() + 1 /* '/' */)) + path.length(); // total length of path

            if (is_file(path)) {
                // update maxlen if needed
                maxlen = max<int>(len, maxlen);
            }

            st.push(len);
        }

        return maxlen;
    }
};
```
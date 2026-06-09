```
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
    static bool cmp(const string& x, const string& y) {
        int x_first = x.find(' ') + 1, y_first = y.find(' ') + 1;
        if (isdigit(x[x_first]) && isdigit(y[y_first])) {
            return false;
        } else if (isdigit(x[x_first]) != isdigit(y[y_first])) {
            return isalpha(x[x_first]);
        } else {
            string x_sub = x.substr(x_first), y_sub = y.substr(y_first);
            return x_sub == y_sub ? x.substr(0,x_first-1) < y.substr(0,y_first-1) : x_sub < y_sub;
        }
    }
};
```

```
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        string x;
        map<string , int> s;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] != ' ' && i != A.size() - 1) {
                x = x + A[i];
            } else {
                if(i == A.size() - 1) {
                    x = x + A[i];
                }
                if(s.find(x) != s.end()) {
                    s[x]++; 
                } else {
                    s.insert(map<string , int> ::value_type(x, 1));
                }
                cout << x << s[x] << endl;
                x.clear();
            }
        }
        string y;
        for(int j = 0; j < B.size(); ++j) {
            if(B[j] != ' ' && j != B.size() - 1) {
                y = y + B[j];
            } else {
                if(j == B.size() - 1) {
                    y = y + B[j];
                }
                if(s.find(y) != s.end()) {
                    s[y]++;
                } else {
                    s.insert(map<string , int> ::value_type(y, 1));
                }
                cout << y << s[y] << endl;
                y.clear();
            }
        }
        vector<string> ret;
        for(auto it = s.begin(); it != s.end(); ++it) {
            if(it->second == 1)
            ret.push_back(it->first);
        }
        return ret;
    }

};
```
![image.png](https://pic.leetcode-cn.com/9c25df313ff3a9289f9483c59ed0d128fc99580f41e82dd0f1cea29bc0ab0f47-image.png)

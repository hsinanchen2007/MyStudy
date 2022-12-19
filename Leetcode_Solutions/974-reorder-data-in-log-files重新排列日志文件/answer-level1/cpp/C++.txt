### 解题思路
字符类型的定义一下排序规则，排序一下即可

### 代码

```cpp
class Solution {
public:
    static bool cmp(string a, string b) {
        int j = 0;
        for (; j < a.size(); j++) {
            if (a[j] == ' ') {
                // printf("j inside=%d\n", j);
                break;
            }
        }
        // printf("j=%d\n", j);
        string keyA = a.substr(0, j);
        string valueA = a.substr(j + 1);
        int k = 0;
        for (; k < b.size(); k++) {
            if (b[k] == ' ') {
                break;
            }
        }
        string keyB = b.substr(0, k);
        string valueB = b.substr(k+1);
        /*
        printf("keyA=%s\n", keyA.c_str());
        printf("keyB=%s\n", keyB.c_str());
        printf("valueA=%s\n", valueA.c_str());
        printf("valueB=%s\n", valueB.c_str());
        */
        if (valueB != valueA) {
            return valueA < valueB;
        } else {
            return keyA < keyB;
        }
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        int size = logs.size();
        
        vector<string> ans;
        if (size == 0) {
            return ans;
        }
        vector<string> astr;
        vector<string> nstr;
        for (int i = 0; i < size; i++) {
            string log = logs[i];
            int j = 0;
            for (j = 0; j < log.size(); j++){
                if (log[j] == ' ') {
                    break;
                }
            }
            if (log[j + 1] >= 'a' && log[j + 1] <= 'z') {
                astr.push_back(log);
            } else {
                nstr.push_back(log);
            }
        }
        sort(astr.begin(), astr.end(), cmp);
        for (int i = 0; i < nstr.size(); i++) {
            astr.push_back(nstr[i]);
        }
        return astr;
    }
};
```
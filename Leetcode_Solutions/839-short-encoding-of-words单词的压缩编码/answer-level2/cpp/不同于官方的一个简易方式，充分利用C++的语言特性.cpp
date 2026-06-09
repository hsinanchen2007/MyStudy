### 解题思路
1. 长度大的String先放入到resutl，长度小的String后放入到结果；
2. 利用string.find查找“子符串+#”。
简洁易懂。

### 代码

```cpp
class Solution {
private:
    struct _compareSize {
        bool operator()  (const string &s1, const string &s2) {
            return s1.size() < s2.size();
        }
    };
public:
    int minimumLengthEncoding(vector<string>& words) {
        priority_queue<string, vector<string>, _compareSize> pq(words.begin(), words.end());

        string result;
        while (!pq.empty()) {
            const string &t = pq.top();
            
            auto found = result.find(t + "#");
            if (found != string::npos) {
                pq.pop();
                continue;
            } else {
                result += t + "#";
                pq.pop();
            }
        }
        
        return result.length();
    }
};
```
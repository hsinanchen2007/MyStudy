### 解题思路
首先，定义快排，把每个字符串按照字母从小到大排序
保存好原始字符串
将排序好的字符串作为key，　原始字符串加入到key对应的vector中。
最后遍历一遍哈希表即可获得答案

### 代码

```cpp
class Solution {
public:
    void sortStr(string& s, int left, int right) {
        if (left < right) {
            
            int i = left; 
            int j = right;
            char x = s[i];
            while (i < j) {
                while (i < j && s[j] > x) {
                    j--;
                }
                if (i < j) {
                    s[i++] = s[j];
                }
                while (i < j && s[i] < x){
                    i++;
                }
                if (i < j) {
                    s[j--] = s[i];
                }
            }
            s[i] = x;
            sortStr(s, left, i - 1);
            sortStr(s, i + 1, right);
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        
        vector<vector<string>> ans;
        if (size == 0) {
            return ans;
        }
        if (size == 1) {
            vector<string> tmp = {strs[0]};
            ans.push_back(tmp);
            return ans;
        }
        unordered_map<string, vector<string>> record;
        for (int i = 0; i < size; i++) {
            string str = strs[i];
            string real = str;
            sortStr(str, 0, str.size() - 1);
            
            if (record.count(str) == 0) {
                record[str] = {real};
            } else {
                record[str].push_back(real);
            }
        }
        unordered_map<string, vector<string>>::iterator it;
        for (it = record.begin(); it != record.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
```
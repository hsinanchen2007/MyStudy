### 解题思路
排列问题，要么选，要么不选；
没选择一次，就不用再考虑了。
递归的时候，尽量不要删除；题目给了哈希表，最好用数组代替。

### 代码

```cpp
class Solution {
public:
int DFSGetMaxStr(int cur, vector<string>& arr, vector<int>& hash) {
    if (cur == arr.size()) {
        return 0;
    }
    bool flag = true;
    for (int i = 0; i < hash.size(); i++) {
        if (hash[i] != 1) {
            flag = false;
        }
    }
    if (flag) {
        return 0;
    }
    int ans = 0;
    for (int i = cur; i < arr.size(); i++) {
        flag = true;
        vector<int> ttt(hash);
        for (int j = 0; j < arr[i].size(); j++) {
            if (ttt[arr[i][j] - 'a'] == 1) {             
                flag = false;
                break;
            } else {
                ttt[arr[i][j] - 'a'] = 1;
            }
        }
        int length = arr[i].size();
        if (flag) {
            ans = max(ans, length + DFSGetMaxStr(i + 1, arr, ttt));
        }
    }
    return ans;
}
    int maxLength(vector<string>& arr) {
        vector<int> hash(26,0);
        return DFSGetMaxStr(0, arr, hash); 
    }
};
```
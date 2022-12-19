顺序遍历数组，遇到0就插入一个0，同时pop一个元素

代码：
```
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        for (int i = 0; i < len; i++) {
            if (arr[i] == 0) {
                arr.insert(arr.begin() + i, 0);
                arr.pop_back();
                i++;
            }
        }
    }
};
```

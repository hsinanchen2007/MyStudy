### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void wiggleSort(vector<int>& a) {
        if (a.size() < 3)
            return;
        int len = a.size();
        bool next = (a[1] > a[0]); //峰是1，谷是0
        for(int i = 0; i < len - 2; i++) {
            if (a[i] < a[i + 1] && a[i + 1] < a[i + 2]) {
                swap(a[i + 1], a[i + 2]);
            } else if (a[i] > a[i + 1] && a[i + 1] > a[i + 2]) {
                swap(a[i + 1], a[i + 2]);
            } else if (a[i] == a[i + 1] && a[i + 1] < a[i + 2] && next) {
                swap(a[i + 1], a[i + 2]);
            } else if (a[i] == a[i + 1] && a[i + 1] > a[i + 2] && !next) {
                swap(a[i + 1], a[i + 2]);
            }

            next = !next;
            
        }
    }
};
```
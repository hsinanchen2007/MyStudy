### 解题思路
会写排列就可以做出这道题目
无非是在是否进入下层递归前做一个判断，如果题目中两个条件都不满足，就跳过当前位置的交换。

### 代码

```cpp
class Solution {
public:
    vector<int> arr;
    int count = 0;
    int countArrangement(int N) {
        for (int i = 0; i < N; ++i) arr.push_back(i+1);
        countnumber(0);
        return count;
    }
    void countnumber(int pos) {
        if (pos >= arr.size()) {
            count ++;
            return;
        }
        for (int i = pos; i < arr.size(); ++i) {
            if (arr[i] % (pos+1) && (pos+1) % arr[i]) continue;
            swap(arr[pos], arr[i]);
            countnumber(pos+1);
            swap(arr[pos], arr[i]);
        }
    }
};
```
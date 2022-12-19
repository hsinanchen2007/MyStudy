### 解题思路
这道题在剑指offer40做过，，然后发现快排partition写的很烂。堆排序的方法完全忘了。。
在解题里面发现了这个c++自带的函数nth_element。。。

必须要会写所有排序啊。！！！ 马上去写排序。！！！

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() <= k)
        {
            return arr;
        }

        nth_element(arr.begin(), arr.begin() + k, arr.end());
        arr.resize(k);
        return arr;
    }
};
```
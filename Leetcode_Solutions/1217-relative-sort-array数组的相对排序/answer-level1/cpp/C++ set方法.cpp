### 解题思路
    把arr1数组的元素放到multiset中，然后遍历arr2通过arr2的元素查表并统计元素出现次数，放入结果数组中，从表中删去这些元素。最后跳出循环，将表中剩余的元素插入到结果数组中，此题得解。

### 代码

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        multiset<int>set;
        vector<int>ans;
        for(int i : arr1)
        {
            set.insert(i);
        }
        for(int i : arr2)
        {
            int cnt = set.count(i);
            for(int j=0 ; j<cnt ; j++)
            {
                ans.push_back(i);
            }
            set.erase(i);
        }
        for(auto i : set)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
```
首先建立一个哈希表，用于实现字符串和其索引之间的哈希映射，节约查找时间。

再遍历另一组字符串，如果发现已经存在的字符串，计算索引值的和，确定是否更新最小值，如果更新则需要清空vec里面的内容。（一开始想用一个迭代器记录最后删除的起点和终点，这样只需要删除vec里的元素一次，可惜没写出来。。。）

由于题目里说到“如果答案不止一个，则输出所有答案并且不考虑顺序”，所以如果索引值的和等于最小值，那么也将其加入vec中。

算法的整体时间复杂度应该是O(n);

![1.png](https://pic.leetcode-cn.com/4425e7c7528cd4d53c406f385fc063df3ce3c0cec2088bb5fd010207e9376f62-1.png)

代码：
```
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> vec;
        unordered_map<string, int> hashmap;
        int MIN = 2000;
        
        for (int i = 0; i < list1.size(); i++)
            hashmap[list1[i]] = i;
        
        for (int i = 0; i < list2.size(); i++) {
            if (hashmap.count(list2[i]) > 0) {
                if (hashmap[list2[i]] + i < MIN) {
                    vec.clear();
                    MIN = hashmap[list2[i]] + i;
                    vec.push_back(list2[i]);
                }
                else if (hashmap[list2[i]] + i == MIN)
                    vec.push_back(list2[i]);
            }
        }
        
        return vec;
    }
};
```

**（萌新初学C++，又是第一次写题解，如果有说的不对的地方希望大家可以指正，如果算法能继续优化的话也欢迎分享😁😁😁）**

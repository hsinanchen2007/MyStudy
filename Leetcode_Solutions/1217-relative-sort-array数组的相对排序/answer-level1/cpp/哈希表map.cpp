### 头文件
```
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
```

### 解题思路
1，将arr2从小到大排序，为步骤4做铺垫；
2，使用map函数，将arr2中不同数值的数量统计出来；
3，依照arr1的顺序传值；
4，将未在arr1中出现的值按照从小到大的顺序输出。
```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if (arr2.empty())
            return {}; //首先判断数组2是否为空
        map<int, int> mapping;
        vector<int> res;
        sort (arr1.begin(), arr1.end());
        for (auto c:arr1)
            mapping[c]++;
        for (auto c:arr2){
            res.insert(res.end(),mapping[c],c);
            mapping[c]=0; //这句很重要，要保证下一个for循环的可用性，即不能删除mapping的值；
        }
        for (auto c:arr1){
            res.insert(res.end(),mapping[c],c);
            mapping[c]=0;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c4df06658d7aaa38726beea722784f1ed73e69450ebe3078862d3988b592b1c9-image.png)

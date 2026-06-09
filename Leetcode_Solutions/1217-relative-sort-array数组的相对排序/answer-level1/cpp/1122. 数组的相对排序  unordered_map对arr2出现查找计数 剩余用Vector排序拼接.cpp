![1122.jpg](https://pic.leetcode-cn.com/b29e35423330d583285bd91151ce3ed8cd44b9425785d91992e9ef43ccca28aa-1122.jpg)

### 解题思路
注意已经给出了两个限制：
（1）arr2不重，故而每个Key只有一个value；
（2）arr2中的元素arr1均出现，故而不用考虑查找不到的情况

把arr2的都入hash map，
key为值，value为出现次数，初始为0
遍历arr2建好表
遍历arr1给表填值（通过find ->second++的方式），若没找到则入一个vector最后排序拼接

### 代码

```cpp
//对于arr2中的每个元素
//  首先要对arr2中的元素去重，不必，因为各不相同
//  转存为一种方便查找的结构，并且要方便记录其出现次数
//  采用unordered_map
//   未出现的记录在专门的vector中，之后再拼接
//记录arr1中该元素出现的次数，其余的放在末尾

#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //arr2转存为方便查找的unordered_map
        unordered_map<int, int> myMap;
        for(vector<int>::iterator iteArr2 = arr2.begin(); iteArr2 != arr2.end(); ++iteArr2)
        {
            //已经确保arr2不重复
            myMap.insert(make_pair(*iteArr2, 0));
        }

        vector<int> otherVec;
        for(vector<int>::iterator iteArr1 = arr1.begin(); iteArr1 != arr1.end(); ++iteArr1)
        {
            //找到， cnt+1
            auto resFd = myMap.find(*iteArr1);
            if(resFd != myMap.end())
            {
                resFd->second++;
            }
            else
            {//没找到
                otherVec.push_back(*iteArr1);
            }
        }

        sort(otherVec.begin(), otherVec.end());
        vector<int> resVec;
        for(vector<int>::iterator iteArr2 = arr2.begin(); iteArr2 != arr2.end(); ++iteArr2)
        {
            //保证都至少出现一次
            for(int i = 0; i < myMap.find(*iteArr2)->second; ++i)
            {
                resVec.push_back(*iteArr2);
            }
        }
        for(vector<int>::iterator iteOther = otherVec.begin(); iteOther != otherVec.end(); ++iteOther)
        {
            resVec.push_back(*iteOther);
        }
        return resVec;
    }
};

```
其他题解中用到了特殊argument排序，也是很优美的方法。
依照arr2的顺序设置argument值，再sort是重定义比较函数。




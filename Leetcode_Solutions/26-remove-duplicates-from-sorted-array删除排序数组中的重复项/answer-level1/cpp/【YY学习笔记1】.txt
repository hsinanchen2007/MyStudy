### 解题思路
本题先看了答案解析，然后自己复刻
### 知识点
**1.**  双指针：采用双指针完成重复项的删除（题中已经指明是已“排序”的数组）。
**2.**  vector容器：向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。跟任意其它类型容器一样，它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放任意类型的动态数组。 
**3.**  vector函数：int size() const，返回向量中元素的个数。
**4.**  return i+1（Y），return i++（N）。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(size(nums)==0)return 0;
        int i=0;
        for(int j=1;j<size(nums);j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }

        }
        return i+1;
    }
};
```
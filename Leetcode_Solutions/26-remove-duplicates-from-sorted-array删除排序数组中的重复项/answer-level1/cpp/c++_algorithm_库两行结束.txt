### 解题思路
![QQ图片20200209151219.png](https://pic.leetcode-cn.com/f2c0cde87fab27ff4e51f292337725459bc18d2f3a3e7f2342789ed865d4b49a-QQ%E5%9B%BE%E7%89%8720200209151219.png)
使用c++<algorithm>库中的unique()函数和vector自带的erase()函数来解决。unique函数形式为unique(iterator first, iterator last)；其将重复的元素放到vector的尾部，然后返回指向第一个重复元素的迭代器。erase函数形式为
iterator erase(iterator position);
iterator erase(iterator first, iterator last);
第一个表示删除某一固定位置的元素
第二个可以删除从某个位置至另外一个 位置之间的元素

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};
```
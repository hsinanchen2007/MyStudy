### 解题思路
    使用两个标记index, num
    index表示遍历的位置，从1开始一直到最后
    num统计数组中不同元素的个数

    这样做比发现一个相同的元素就删除它的做法效率要高挺多的
    应为remove的复杂度本身就是O(N)
    加上遍历的时间，总的时间复杂度将会高达O(N)

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size ()) return 0;                        // 千万别忘了这种特殊情况
        int index = 0;
        int num = 1;                                        // 两个标记
        for (int i = 0; i < nums.size() - 1; ) {            // 遍历一轮
            if (nums[i++] != nums[++index]) {               // 如果遇到不同的值
                nums [num++] = nums[i = index];             // 把这个不同的值往前移，然后i调到index的位置
            }
        }
        nums.erase (nums.begin () + num, nums.end ());      // 遍历完成后把后面多余的元素擦除，留下的都是不同的元素
        return num;                                         // 返回剩余元素总个数
    }
};
```
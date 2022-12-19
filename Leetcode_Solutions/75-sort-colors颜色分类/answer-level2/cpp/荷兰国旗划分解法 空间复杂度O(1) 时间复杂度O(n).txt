### 解题思路
如果你知道荷兰国旗划分，这个问题是比较容易求解的。最后的数组元素由三部分组成：左侧是0，中间是1，右侧是2。

我们维护四个子数组：`bottom`（元素小于pivot），`middle` （元素等于pivot），`unclassified`，`top`（元素大于pivot）。一开始所有的元素都是`unclassified`，遍历这个组的元素，根据当前元素与pivot的相对关系将元素划分到`bottom`，`middle`和`top`组。

举个具体的例子：假设数组`nums`为`<-3,0,-1,1,1,?,?,?,4,2>`，其中`1`和`?`分别表示pivot和unclassified元素。对于第一个未分类的元素，`nums[5]`，共有三种可能性：

* `nums[5] < pivot`，例如`nums[5] = -5`。我们将其与第一个`1`进行交换，得到新数组为`-3,0,-1,-5,1,1,?,?,4,2>`。
* `nums[5] == pivot`，例如`nums[5] = 1`。我们无需作任何移动，继续考察下一个未分类的元素，新数组为`-3,0,-1,1,1,1,?,?,4,2>`。
* `nums[5] > pivot`，例如`nums[5] = 3`。我们将其与未分类的最后一个元素进行交换，得到新数组为`-3,0,-1,1,1,?,?,3,4,2>`。

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // invariants:
        // bottom: nums[0, smaller - 1]
        // middle: nums[smaller, equal - 1]
        // unclassified: nums[equal, larger - 1]
        // top: nums[larger, nums.size() - 1]
        int smaller = 0, equal = 0, larger = nums.size();
        // keep iterating as long as there is an unclassified element 
        while (equal < larger) {
            if (nums[equal] < 1) swap(nums[smaller++], nums[equal++]);
            else if (nums[equal] == 1) ++equal;
            else swap(nums[equal], nums[--larger]);
        }
    }
};
```
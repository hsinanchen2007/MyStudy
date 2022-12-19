### 解题思路
我知道我过分了。。

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        Arrays.sort(nums);
        return nums;
    }
}
```

### 解题思路
**快速排序**
（重写了一版更易理解的）
快排也是一种分而治之的思想，每次递归只做两件事：
- 找到数字`p`的正确位置，快排快就快在这里，这个位置是最终位置，不会再随着之后的递归而变化了，找位置通过`partition`来实现，是快排的重点
- 把比`p`小的都放在`p`的左边，大的都放在右边，这时只保证它们和`p`之间的相对位置正确，至于它们各个数之间的排序在后续的递归中再来完成

然后再说说`partition`这个函数具体怎么实现的
- 首先是在数组中找一个数作为`p`，通常的做法是随机选择一个，或是找前中后3数中的中位数，选择方法不同对快排的效率也是有影响的，这里不做展开，相对省事的选最右的数为`p`
- 用两个指针`i`和`j`来从左向右遍历数组，`j`会扫描数组上的所有数直到最右，如果发现比`p`小的数，就把它与`i`位置的数交换，`i`维护比`p`小的这些数的最右端位置
- 这样就保证了当`j`扫描完后，比`p`小的都去了`i`的左边，剩下的在`i`右边的就都是比`p`大的数了，此时`i`的位置就是数字`p`的正确位置，将其插入进来

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        quicksort(nums, 0, nums.length-1);
        return nums;
    }

    public void quicksort(int[] nums, int l, int r) {
        if(l < r) {
            int p = partition(nums, l, r);
            quicksort(nums, l, p-1);
            quicksort(nums, p+1, r);
        }
    }

    public int partition(int[] nums, int l, int r) {
        int p = nums[r];
        int i = l;
        for(int j=l; j<r; j++) {
            if(nums[j] < p) {
                swap(nums, i, j);
                i += 1;
            }
        }
        swap(nums, i, r);
        return i;
    }

    public void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
```
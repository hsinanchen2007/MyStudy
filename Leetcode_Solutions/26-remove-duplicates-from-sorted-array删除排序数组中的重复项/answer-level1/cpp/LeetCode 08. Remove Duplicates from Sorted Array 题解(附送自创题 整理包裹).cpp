## 08. Remove Duplicates from Sorted Array 题解

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

> Given nums = [1,1,2],  
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.  
It doesn't matter what you leave beyond the returned length.

Example 2:

> Given nums = [0,0,1,1,1,2,2,3,3,4],  
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.  
It doesn't matter what values are set beyond the returned length.


## 题解思路 双指针

 题意是让我们实现一下STL中的unique函数，这其实是道比较简单的双指针题目，但如果编程的基本功不扎实，或是日常写代码只是 brute force 粗快猛搞的人，突然看到会比较懵，而理不清思路。其实这种题目是有基本套路的，套路方法存在于伟大快排算法中，我们不妨复习默写一下快排的partition函数：

```cpp
int partition(int a[], int l, int r)
{
    int pos = l - 1;
    for (int i = l; i < r; ++i) {
        if (a[i] < a[r]) swap(a[++pos], a[i]);
    }

    swap(a[++pos], a[r]);
    return pos;
}
```
partition要实现的功能，就是在数组中找到一个轴点pivot，将待排序数组中所有小于pivot的元素都放到pivot左边，大于等于piovt的元素放到piovt右边。其实partition的过程分为5步：
1. 选定pivot，这里是待排序数组的最后一个元素a[r]
2. 确定遍历指针i的遍历范围，显然是[l, r)，因为轴点a[r]不需要和自己比较处理
3. 确定待处理位置指针pos，因为个人喜欢 ++pos 写法，所以pos设为左侧第一个无效的位置，即 l - 1，这样 ++pos 后就是待处理的位置
4. 写一个类似 ```bool check(a[i], pivot)``` 的函数，使其性质满足题目要求，这里的check函数可以简化为 ```a[i] < a[r]```
5. 写一个类似 ```oper(a[++pos], a[i])``` 的函数，就是当check函数为true时，对待处理的 a[++pos] 进行满足题意的操作，这里oper函数简化为 ```swap(a[++pos], a[i])```

---

复习完partition，我们回到本题，给定一个排序数组，你需要在 "原地" 删除重复出现的元素。我们尝试用同样的套路来思考：
1. 选pivot，题目要求删除重复元素，那么要比较的pivot首先就是nums[0]，更新完第一个元素后就是nums[1]，以此类推
2. 确定遍历指针i的遍历范围，若数组的元素个数为n，遍历范围[l, r]应该是[1, n - 1]
3. 确定待处理位置指针pos，pos设为第一个无效的位置，即 l - 1，这样 ++pos 后就是待处理的位置，那么pos应该初始化为0，同时，结合步骤1我们发现每步遍历的pivot其实就是nums[pos]
4. 写一个类似 ```bool check(nums[i], pivot)``` 的函数，使其性质满足题目要求，题目要求元素不重复，就是 ```nums[i] != nums[pos]```
5. 写一个类似 ```oper(nums[++pos], nums[i])``` 的函数，就是当check函数为true时，对待处理的 nums[++pos] 进行满足题意的操作，这里可以用覆盖操作，oper函数简化为 ```nums[++pos] = nums[i])```

综上所述，我们不难写出代码：

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int pos = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[pos] != nums[i]) nums[++pos] = nums[i];
        }
        
        return ++pos;
    }
};
```

----

我们再用另外一题来强化一下记忆，这是我作为面试官时出的一道题目，题目本身并不困难，和实际的工作内容相结合。解法众多，可以考察面试者的思考能力和分析问题的方法，很适合作为热身题。

在网络游戏中，玩家一般会有一个包裹系统，而在经过若干次的获得物品，和使用物品后，背包内的物品位置将会出现一种不连续的状态，此时，玩家会选择整理背包，将物品整齐排到背包前面的位置。我们简化定义背包内的物品为一个整数，定义空的位置为0值，有物品的位置为非0值，请写一个函数，实现整理包裹的操作，请保持包裹内物品的相对位置是稳定的，并返回包裹内第一个空位。

示例：
> 首先程序会读入一个n，表示包裹格子的数量。接下来会读入n个数，例如  
给定 inventory = [0, 0, 1, 0, 2, 0, 9, 0, 5, 0]  
程序结束时  
返回 inventory = [1, 2, 9, 5, 0, 0, 0, 0, 0, 0]，包裹的第一个空位置的index是4

思考套路：
1. 选pivot，题目直接给了，就是0
2. 确定遍历指针i的遍历范围，若数组的元素个数为n，遍历范围[l, r]应该是[0, n - 1]
3. 确定待处理位置指针pos，pos设为第一个无效的位置，即 l - 1， 这样 ++pos 后就是待处理的位置
4. 写一个类似 ```bool check(a[i], pivot)``` 的函数，使其性质满足题目要求，题目要求包裹格子非空，就是 ```a[i] != pivot```
5. 写一个类似 ```oper(a[++pos], a[i])``` 的函数，就是当check函数为true时，对待处理的 a[++pos] 进行满足题意的操作，这里oper函数简化为 ```swap(a[++pos], a[i])```，表示将一个物品交换到包裹合适的位置

示例代码：
```cpp
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 100;

int compress_inv(int a[], int l, int r, int pivot)
{
    int pos = l - 1;
    for (int i = l; i <= r; ++i) {
        if (a[i] != pivot) swap(a[++pos], a[i]);
    }
    
    return ++pos;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    int a[N] = {0};
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    
    int index = compress_inv(a, 0, n - 1, 0);
    
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n%d\n", index);
    
    return 0;
}
```
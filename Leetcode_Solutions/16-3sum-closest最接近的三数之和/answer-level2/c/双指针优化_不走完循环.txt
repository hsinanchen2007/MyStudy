### 解题思路
大部分优化参考这个老哥的题解[Karua](https://leetcode-cn.com/problems/3sum-closest/solution/dui-shuang-zhi-zhen-fa-jin-xing-yi-dian-you-hua-da/)。
比如左右指针去重，以及外层i循环去重过程的优化，参考这个。
但是其中有一个判断指针上下界是否大于或小于target的，个人认为，每轮判断还不如不判断，因为不成立的可能多一点。

### 1.此轮是否更新最短距离
同时也受到双指针上下界取值的参考，TwoPointerRange = [nums[i]+nums[left]+nums[left+1],nums[i]+nums[right]+nums[right-1]。
由于数组升序且i从左往右，那么对于每一轮i的值，其后一轮到target距离的最小值可能小于等于或者大于等于上轮最近距离。
由于想优化，即本题给出唯一解可能，因此肯定有找到改解后可以立马结束循环，而不用遍历完。就跟冒泡排序一样，知道数组已经有序，那么就没有必要再去排序(本题也是这样，不过特殊点)。
因此尝试使用upgrade来代表本轮是否更新，如果一直都没更新，“多半”就是找到唯一解了。

### 2.此轮nums[i]>0?
知道上面随着i增加，三数之和一定在继续增加，那么三个数作为一个整体的threesum有一个增加趋势，那是否可以直接通过此轮是否更新upgrade真假来直接返回呢？

例2：-55 -24 -18 -11 -7 -3 4 5 6 9 11 23 33,target=0
（1）nums[i]是负数：可能下次有距离小的，因为从左往右走！
i=0(-55):-55,23,33,1最小(upgrade=true)
i=1(-24):-24,-11,33,-2;-24,-7,33,2共两个解，都是最短距离，因此需要再看下(upgrade=false)
..
i=3(-11):-11,5,6,0=target,就是答案！
（2）nums[i]>0且没更新:由于nums[i]之后的一定大于0，那么必定距离target越来越大，因此可以提前返回。

可能讲的有点乱，还望大佬们补充，证明下是否正确。

### 代码

```c
void heapify(int *arrs, int n, int i) {
	if (i >= n) return;
	int max = i;  // 保存i值
	int lc = 2 * i + 1, rc = 2 * i + 2;  // 左右结点
	if (lc < n && arrs[lc] > arrs[max]) max = lc;  // 找最大
	if (rc < n && arrs[rc] > arrs[max]) max = rc;
	if (max != i) {
		lc = arrs[max];  // lc暂存arrs[max]值
		arrs[max] = arrs[i];
		arrs[i] = lc;
		heapify(arrs, n, max);  // 再生堆
	}
}

void heapsort(int *arrs, int n) {
	int i = (n - 1) >> 1, tmp;  // 非子叶结点
	for (; i >= 0; i--) heapify(arrs, n, i);
	for (i = n - 1; i >= 0; i--) {
		tmp = arrs[i];  // arrs[0]最大
		arrs[i] = arrs[0];
		arrs[0] = tmp;
		heapify(arrs, i, 0);
	}
}

int threeSumClosest(int* nums, int numsSize, int target){
    heapsort(nums, numsSize);  // 排序
    int closest = nums[0] + nums[1] + nums[2], threesum;
    short i, left, right;
    bool upgrade;
    for (i = 0; i < numsSize - 2; i++) {
        left = i + 1;
        right = numsSize - 1;
        upgrade = false;
        while (left < right) {
            threesum = nums[i] + nums[left] + nums[right];
            if (abs(target - threesum) < abs(target - closest)) {
                closest = threesum;
                upgrade = true;
            }
            if (threesum > target) {
                while (left < right && nums[right] == nums[right - 1])
                    right--;  // 右去重
                right--;  // 再左移1个
            }else if (threesum < target) {
                while (left < right && nums[left] == nums[left + 1])
                    left++;  // 左去重
                left++;  // 再右移1个
            }else  return closest;  // 相等，一定最优！
        }
        if (!upgrade&&nums[i]>0) return closest;  // 关键缩短循环判断
        while (i < numsSize - 2 && nums[i] == nums[i+1]) i++;
    }
    return closest;
}
```
![image.png](https://pic.leetcode-cn.com/a771e3a707c69e636fff8b17bc66f144114ce567d481e1378b4c8bcc8a746e48-image.png)

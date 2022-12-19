### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/cd2e34041a3b474e7611ea1cff8480415a771b6446779d4b15ddbafb514398f3-image.png)

### 代码

```c
#define DEBUG 0
int IsPartLine(int* nums, int index)
{
    if (index == 0) {   // 如果索引左边界，说明未进行旋转，按照是返回
        return 1;
    }

    if (nums[index] < nums[index - 1]) {
        return 1;
    }
    else {
        return 0;
    }
}
int IsOnRightSide(int* nums, int lSide, int rSide, int index)
{
    if(index != lSide && nums[index] <= nums[lSide]) {
        return 1;
    }
    else {
        return 0;
    }
}
int findMin(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1) return 0;

    //计算左边界和右边界，第一个非重复的值
    int lSide = 0;
    int rSide = numsSize - 1;

    while (lSide + 1 < numsSize && nums[lSide] == nums[lSide + 1]) {
        lSide++;
    }
    while (rSide - 1 >= 0 && nums[rSide] == nums[rSide - 1]) {
        rSide--;
    }

    if (DEBUG) {
        printf("lSide = %d, rSide = %d\n",lSide, rSide);
    }
    
    if (rSide - lSide <= 1 || lSide + 1 >= numsSize || rSide - 1 <0) {
        return nums[lSide] < nums[rSide] ? nums[lSide] : nums[rSide];
    }
    if (nums[rSide] > nums[lSide] && nums[rSide - 1] > nums[lSide]) {
        return nums[lSide];
    }

    //通过二分法寻找分界点
    int left = lSide;
    int right = rSide;
    int middle = 0;

    if (IsPartLine(nums, left + 1)) {
        return nums[left + 1];
    }
    if (IsPartLine(nums, right)) {
        return nums[right];
    }

    while (right - left > 1) {
        middle = (left + right) / 2;
        if (DEBUG) {
            printf("left = %d, right = %d, middle = %d, IsPartLine = %d, IsOnRightSide = %d\n",
            left, right, middle, IsPartLine(nums, middle), IsOnRightSide(nums, lSide, rSide, middle));
        }
        if (IsPartLine(nums, middle)) {
            return nums[middle];
        } else if (IsOnRightSide(nums, lSide, rSide, middle)) {
            right = middle;
        } else {
            left = middle;
        }
    }

    return nums[right];
}
/* test case
In:  [1,3,5]
Out: 1

In:  [3,5,1]
Out: 1

In:  [2,2,2,0,1]
Out: 0

In:  [2,2,2,2,2,2]
Out: 2

In:  []
Out: x

In:  [5,5,5,6,7,7,7,1,1,1,2,2,2,3,3,3,4,5,5]
Out: 1

In:  [5,5,5,7,7,5,5,5]
Out: 5

In:  [5,5,5,1,1,1,5,5,5]
Out: 1
*/
```
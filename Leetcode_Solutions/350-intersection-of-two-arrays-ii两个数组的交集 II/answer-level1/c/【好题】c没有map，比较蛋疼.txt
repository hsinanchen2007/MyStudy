### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/3712ae4fda11ca7de09c904bde99bda4e0c13e5a5af2f351dcfd31b238e73b03-image.png)

看了题解，发表两点看法：
1）c语言没有map，可以统计每个数出现的次数，但是没办法随机访问，而map是可以随机访问的
2）进行排序，然后使用双指针法，题目中给出了个一个边界条件，那就是 INT_MIN和1的减法，会导致整数溢出，为了解决这个整数溢出，
有两种办法：
a）在qsort中针对特殊情况特殊处理
b) 把题目的int整数数组 赋值为 long类型数组
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void*a, const void* b)
{
    if (*(int*)a == INT_MIN && *(int*)b > 0) {
        return -1;
    }
    if (*(int*)a > 0 && *(int*)b == INT_MIN) {
        return 1;
    }

    return *(int*)a - *(int*)b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = nums1Size > nums2Size? nums1Size :nums2Size;
    int *res = calloc(*returnSize, sizeof(int));
    
    int index1, index2;
    int k = 0;

    qsort(nums1, nums1Size, sizeof(nums1[0]), cmp);
    qsort(nums2, nums2Size, sizeof(nums2[0]), cmp);
    long num1, num2;

    for (index1 = 0, index2 = 0; index1 < nums1Size && index2 < nums2Size; ) {
        num1 = nums1[index1];
        num2 = nums2[index2];
        if (num1 == num2) {
            res[k++] = nums1[index1];
            index1++;
            index2++;
        }
        else if (num1 < num2) {
            index1++;
        }
        else {
            index2++;
        }
    }

    *returnSize = k;
    return res;
}
```
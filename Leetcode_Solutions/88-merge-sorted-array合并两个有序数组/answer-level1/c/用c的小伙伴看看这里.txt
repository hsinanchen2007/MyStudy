### 解题思路
方法一：
这是最容易就能想到的方法，不废话直接看代码。
结果没法找了。。。。。。

方法二：
参考官方题解和评论下方的一位大佬的代码改编的，思路是利用“双指针”从nums[m+n-1]开始，到0结束。需要注意下这个判断if(x < 0){while(y >= 0){ nums1[p--] = nums2[y--];}},OK如果看完代码还是不太懂得话那就去看看官方题解吧。
执行用时 :
8 ms, 在所有 C 提交中击败了51.78%的用户
内存消耗 :7.3 MB, 在所有 C 提交中击败了72.36%的用户

### 代码
//方法一：
```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = m, j = 0; j < n; i++, j++){
        nums1[i] = nums2[j];
    }
    for(int i = 0; i < m + n; i++){//选择排序
        int k = i;
        for(int j = k; j < m + n; j++){
            if(nums1[k] > nums1[j]){
                k = j;
            }
        }
        int tmp = nums1[k];
        nums1[k] = nums1[i];
        nums1[i] = tmp;
    }
}
//方法二：
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p = m + n - 1, x = m - 1, y = n - 1;
    while(x >= 0 && y >= 0){
        nums1[p--] = nums1[x] > nums2[y] ? nums1[x--] : nums2[y--];
    }
    if(x < 0){
        while(y >= 0){
            nums1[p--] = nums2[y--];
        }
    }
}
```
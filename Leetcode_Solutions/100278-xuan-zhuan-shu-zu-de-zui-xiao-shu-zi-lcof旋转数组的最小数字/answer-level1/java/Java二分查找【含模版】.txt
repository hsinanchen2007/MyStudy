二分查找思路（既适用于无重复元素又适用于有重复元素的旋转数组）：
​二分查找的g函数为：
​	nums[m] < nums[r]说明在左侧r=mid; 
​	nums[m] > nums[r]说明在右侧l=mid+1; 
​	nums[m] == nums[r]  r- -;
```
public int minArray(int[] numbers) {
    int l = 0, r = numbers.length - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (numbers[m] < numbers[r]) r = m;
        else if (numbers[m] > numbers[r]) l = m + 1;
        else r--;
    }
    return numbers[l];
}
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！

**二分查找模版**
```Java
int start = 0, end = length - 1; 
while(start < end) {
        mid = start + (end - start) / 2;
        if g(mid)  
            end = mid ;  // 左侧
        else
            start = mid + 1;  // 右侧
}
return start;  //  How to use upper bound (start) ?
```
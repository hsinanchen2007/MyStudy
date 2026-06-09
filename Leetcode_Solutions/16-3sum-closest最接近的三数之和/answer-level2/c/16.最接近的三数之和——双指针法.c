### 解题思路
$i:0\sim numsSize-3$
每次固定一个数nums[i]，然后left和right分别指向nums[i]之后的首和尾。
如果当前指向的三数之和小于target，就left++；大于target就right--；等于target就直接返回target。
循环的过程中随时更新最接近target的三数之和，注意left不能大于等于right。

**注意事项**：双指针法是常用的方法，必须掌握。双指针法能将暴搜复杂度为$O(n^3)$的问题变成复杂度为$O(n^2)$的问题。

### 代码

```c
int* sort(int* nums,int numsSize){  // 用的冒泡排序，还有更快的
    int temp;
    for(int i=1;i<numsSize;i++){
        for(int j=0;j<numsSize-i;j++){
            if(nums[j]>nums[j+1]){
            temp = nums[j];
            nums[j] = nums[j+1];
            nums[j+1] = temp;
            }
        }
    }
    return nums;
}

int abs(int a){
    if(a<0)return -1 * a;
    else return a;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int result, left, right;
    int temp;
    int n = numsSize;
    if(n < 3)return -1;
    result = nums[0]+nums[1]+nums[2];   // 给result赋初值
    nums = sort(nums, n);
    for(int i = 0;i <= n - 3;i++){
        left = i + 1;
        right = n - 1;
        while(left < right){
            temp = nums[i] + nums[left] + nums[right];
            if(abs(temp-target) < abs(result-target))result = temp;
            if(temp == target)return target;
            else if(temp < target){
                left++;
                continue;
            }
            else{
                right--;
                continue;
            }
        }
    }
    return result;
}
```
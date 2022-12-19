# 解题思路
**oooomxxxx**
- 前部分'oooo': `nums[mid] > nums[start]`
- 中点'm': `nums[mid]`
- 后部分'xxxx': `nums[mid] < nums[end]`
### 情况
因为我们不能确定'oooo'和'xxxx'两个部分中数的大小顺序，所以如果分类的话会需要分很多情况。但是如果我们能确定target在哪一个部分，我们就可以移动start和end的指针位置了。
1. 当 `nums[mid] > nums[start]`     **oooo**m*xxxx*
    只有当`nums[start] <= target < nums[mid]`，即target在'oooo'部分，其他情况下target都在'xxxx'部分。
2. 当`nums[mid] < nums[end]`    *oooo*m**xxxx**
    只有当`nums[mid] < target <= nums[end]`，即target在'xxxx'部分，其他情况下target都在'oooo'部分。

**代码如下**：
```java []
  public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return -1;
        }

        int start = 0;
        int end = nums.length - 1;

        while(start + 1 < end){
            int mid = start + (end - start) / 2;

            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > nums[start]){
                if(target >= nums[start] && target < nums[mid]){
                    end = mid;
                }else{
                    start = mid;
                }
            }else if (nums[mid] < nums[end]){
                if(target <= nums[end] && target > nums[mid]){
                    start = mid;
                }else{
                    end = mid;
                }
            }
        }

        if(nums[start] == target){
            return start;
        }else if (nums[end] == target){
            return end;
        }
            return -1;
    }
```

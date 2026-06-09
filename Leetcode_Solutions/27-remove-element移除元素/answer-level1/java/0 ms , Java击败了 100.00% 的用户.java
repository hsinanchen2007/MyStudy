### 解题思路
1. 三个变量result记录数组中值为val的角标；另外两个是开始和结束的双指针
2. 从头开始，遇到非val，向后，并记录result+1；
3. 若startIndex值为val，则从后面找到非val的值交换

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int result = 0, startIndex =0, endIndex = nums.length-1;
        while(startIndex<endIndex){
            if(nums[startIndex]!=val){
                result++;
                startIndex++;
            }else{
                while(startIndex<endIndex){
                    if(nums[endIndex]!=val){
                        nums[startIndex] = nums[endIndex];
                        nums[endIndex] = val;
                        endIndex--;
                        break;
                    }else{
                        endIndex--;
                    }
                }
            }
        }
        if(nums.length==0){
            return 0;
        }
        if(nums[startIndex]!=val){
            result++;
        }
        return result;
    }
}
```
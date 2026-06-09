### 解题思路
用的是剑指offer中查找重复数的思路，自己再按理解整理一下。
- 首先是区间$[1,n]$内的整数在数组中均出现至少一次；
- 若区间$[1,n]$中的每个数在数组中只出现一次，则任意子区间$[k,k+m]$内的数在数组中应只出现一次；
- 若存在重复数，则某个区间内的数在数组内出现次数会大于该区间长度；

因此，目标就是查找这样的子区间，使用`二分查找`的思想来寻找$[1,n]$中的子区间,满足区间内的数在数组中出现次数大于区间长度，边界条件是区间长度为1时，对应某个数在数组中的出现次数大于1，该数为重复数。

### 代码

```java
class Solution {
    public int findDuplicate(int[] nums) {
        int start = 1, end = nums.length-1;
        while(start<=end){
            int middle = ((end-start)>>1) + start;
            int count = countCalculate(nums, start, middle);
            if(start == end){
                if(count > 1) return start;
                else break;
            }
            if(count>middle-start+1){
                end = middle;
            }else{
                start = middle + 1;
            }
        }
        return -1;
    }
    private int countCalculate(int[] nums, int start, int end){
        if(nums.length < 1) return 0;
        int count = 0;
        for(int n : nums){
            if(n>=start && n<=end){
                count++;
            }
        }
        return count;
    }
}
```
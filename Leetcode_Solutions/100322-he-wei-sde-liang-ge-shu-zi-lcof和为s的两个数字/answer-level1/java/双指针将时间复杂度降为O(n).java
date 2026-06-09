### 解题思路
拿到本题最先想到的就是
固定一个数（设这个数的index为i，从0开始），接下来遍历剩下的n-i个数，看有没有与index为i的那个数相加等于target的数。
如果有就直接return输出，没有就将固定的数的index+1，继续循环。
时间复杂度是O(n^2)，这样的代码好写，但是过不了，超出时间限制了。

题目中强调，这个数组是一个递增排序的数组，因此结合这一条件。
采用双指针法，两个指针，一前一后。head从index=0开始，tail从index=nums.length-1开始。
head往后走，值是越来越大，tail往前走，是越来越小。
如果head+tail的值大于target，说明值大了，因此tail往前移动，这样和就会变小。
如果head+tail的值小于target，说明值小了，因此head往后移动，这样和就会变大。
如果head+tail的值等于target，说明值正好等于target，直接输出head和tail就好了。
双指针法只遍历了一遍数组，因此时间复杂度为O(n)。

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int head = 0, tail = nums.length-1;
        while(head<tail){
            if(nums[head]+nums[tail]>target){
                tail--;
            }else if(nums[head]+nums[tail]<target){
                head++;
            }else{
                return new int[] {nums[head], nums[tail]};
            }
        }
        return null;
    }
}
```
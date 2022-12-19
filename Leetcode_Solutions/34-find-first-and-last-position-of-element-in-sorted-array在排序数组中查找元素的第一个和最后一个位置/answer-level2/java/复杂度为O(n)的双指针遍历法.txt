### 解题思路
这个复杂度为O(n)，不符合题目要求，但是可以作为一种思路
注意几个点：
1. 空数组
2. 头尾指针向中间靠拢的过程中，头尾指针相等时，最后一次没有处理，所以要单独处理
3. 有可能只有一个元素，尾指针先占到；也可能头指针先占到，所以要处理这种倒置的情况

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 0){
            return new int[]{-1,-1};
        }

        // 思路
        // 使用双指针向内收敛
        // 如果头指针和尾指针碰到一起就结束循环
        int head = 0;
        int tail = nums.length-1;
        boolean foundHead = false;
        boolean foundTail = false;
        while(head < tail && (!foundHead || !foundTail)){
            if(nums[head] != target){
                head++;
            }else{
                foundHead = true;
            }
            if(nums[tail] != target){
                tail--;
            }else{
                foundTail = true;
            }
        }
        // 处理结尾，双指针碰到一起的情况
        if(head==tail && nums[head] == target){
            foundHead = true;
            foundTail = true;
        }
        // 尾巴比头大
        if(foundHead && !foundTail){
            tail = head;
        }
        if(!foundHead && foundTail){
            head = tail;
        }
        if(!foundTail && !foundHead){
            head = -1;
            tail = -1;
        }
        return new int[]{head,tail};
    }
}
```
``` java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0, p1 = 0, p2 = 0;
        int len = nums.length;
        while (p2 < len){
            int cnt = 0;
            //p2用于统计连续1的个数，遇到0则一次统计结束，p2指向0之后的1的下标
            while (p2 < len && nums[p2++] == 1)
                cnt++;
            if (cnt > max)
                max = cnt;
            p1 = p2;//更新慢指针，p1指向0之后的1的下标
        }
        return max;
    }
}
```

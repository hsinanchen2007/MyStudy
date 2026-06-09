```
class Solution {
    public static int firstMissingPositive(int[] nums) {
        int ans = 1;
        if(nums.length == 0)
            return 1;
        //把原数组改造成哈希数组
        int len = nums.length;
        int hashTime = 0;
        for (int i = 0; i < nums.length; i++) {
            if(nums[i]>0){
                hashTime = myHash(nums,hashTime,i);
            }
        }
        for (int i = 0; i < len; i++) {
            if(i+1 != nums[i])
                return i+1;
        }
        return len+1;
    }
    private static int myHash(int[] nums,int hashTime,int index){
        hashTime++;
        int hashIndex = hashCode(nums[index],nums.length);
        if(hashTime > nums.length || hashIndex == index)
            return hashTime;
        //如果不同，并且hashCode对应的数小于等于0
        if(nums[hashIndex] <= 0){
            nums[hashIndex] = nums[index];
        }
        //如果大于0
        else{
            int newHashIndex = hashCode(nums[hashIndex],nums.length);
            if(newHashIndex == hashIndex){
                nums[hashIndex] = nums[hashIndex] > nums[index] ? nums[index] : nums[hashIndex];
            }
            else {
                int num = nums[index];
                myHash(nums,hashTime,hashIndex);
                nums[hashIndex] = num;
            }
        }
        return hashTime;
    }
    private static int hashCode(int x,int len){
        int hashCode = x % len;
        return hashCode == 0? len-1: hashCode-1;
    }
}
```

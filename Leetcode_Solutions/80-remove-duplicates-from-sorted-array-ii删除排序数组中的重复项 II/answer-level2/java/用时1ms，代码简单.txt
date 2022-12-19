```java 
public class Leetcode80 {
    public int removeDuplicates(int[] nums) {
        if(nums.length<=2){
            return nums.length;
        }
        //因为允许最多两次的重复数，所以可以从第二个开始。
        int index=1;
        //记录当前数字的重复次数，初始为1
        int count=1;
        //同index
        for(int i =1;i<nums.length;i++){
                //如果当前数字和前一个相同，则分为两种情况，count如果为1.则将当前的数放入nums中，并且计数器加1，
                // 如果计数器不等于1，则说明nums中已经有两个重复的数了，直接回到循环，continue是为了思路，可以去掉
                if(nums[i]==nums[i-1]){
                    if(count==1){
                        nums[index++]=nums[i];
                        count++;
                    }else {
                        continue;
                    }
                }else {
                    //如果当前的数字和前一个不等，则放入数组中，计数器清1
                    nums[index++]=nums[i];
                    count=1;
                }
        }
        return index;
    }
}
```
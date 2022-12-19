### 解题思路
执行用时:1 ms,在所有Java 提交中击败了95.82%
时间复杂度：最好一次遍历，最差两次遍历，O(N)
### 代码

```java
class Solution {
    //主要思想，把数字放在相应位置，1->nums[0],2->nums[1],...
    public int firstMissingPositive(int[] nums) {
        int minPosNum = 0;//简单记个数，可以不要，使用循环放置数字后从头遍历即可
        for(int i=0;i<nums.length;i++){
            if(nums[i]==minPosNum+1) {minPosNum++;}//发现刚好这个数比已知存在的最小正数大1，更新一下
            if(nums[i]>nums.length) {continue;}//数字大于数组长度，那所求必小于数组长度，这个数字不关心了
            if(nums[i]-1==i) {continue;}//这个数就应该在这个位置，很好，不动你了

            //到了这里，说明这个数的位置不对，和正确位置的交换
            while(nums[i]>0){//大于0就判断是否需要交换
                
                if(nums[i]==nums[nums[i]-1]) {break;}//正确位置已经有正确数了，不关心这个数了
                swap(nums,i,nums[i]-1);//交换

                //交换后的判断，同上
                if(nums[i]==minPosNum+1) {minPosNum++;}
                if(nums[i]>nums.length) {break;}
                if(nums[i]-1==i) {break;}
            }
        }

        //放置结束
        //到了这其实minPosNum只有两种情况，nums.length或者小于nums.length

        //大于等于数组长度说明刚好12345这样，返回长度+1(习惯了>=，直接==也行)
        if(minPosNum>=nums.length){
            return nums.length+1;
        }

        //minPosNum前的肯定已经存在，从它开始找，直到发现某个位置放着不应该在这里的数
        for(int i=minPosNum;i<nums.length;i++){
            if(nums[i]!=i+1) return i+1;
        }

        //如果使用minPosNum返回什么都行，不会运行到这；不使用就得返回nums.length+1
        return nums.length+1;
    }

    public void swap(int[] nums,int a, int b){  
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        return; 
    }
}
```
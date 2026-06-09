解题思路：遍历数组，如果遇到0，就向前遍历0之前的元素：如果存在某元素a的值 > 0所在位置与a所在位置的距离(即nums[j] > i-j)，那么这个数组一定能跨越这个0，继续寻找下一个0；如果遍历完这个0前面的所有元素，不存在某元素a的值 > 0所在位置与a所在位置的距离（即count==i），则返回false。
```
class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length==1){ 
            return true;
        }
        if(nums==null || nums[0]==0){
            return false;
        }
        for(int i = 0; i<nums.length-1; i++){
            if(nums[i]==0){
                int count = 0;
                for(int j = i-1; j>=0; j--){
                    if(nums[j] > i-j){
                        break;
                    }else{
                        count++;
                    }
                }
                if( count==i){
                    return false;
                }             
            }
        }
        return true;
    }
}
```



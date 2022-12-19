```
class Solution {
    
    public void wiggleSort(int[] nums) {
        int count = nums.length, big_count = 0, small_count = 0;
        int[] big , small;
        
        if(count % 2 == 1){
            big_count = count/2;
            small_count = count/2 + 1;
        }else{
            big_count = count/2;
            small_count = count/2;
        }
        big = new int[big_count];
        small = new int[small_count];
        Arrays.sort(nums);
        for(int i=0;i<small_count;i++){
            small[small_count-i-1] = nums[i];
        }
    
        for(int i=small_count;i<count;i++){
            big[i-small_count] = nums[i];
        }
    
        int small_index = 0, big_index = big_count-1;
        for(int i=0;i<count;i++){
            if(i % 2 == 0){
                nums[i] = small[small_index];
                small_index++;
            }else{
                nums[i] = big[big_index];
                big_index--;
            }
        }
    }
}
```

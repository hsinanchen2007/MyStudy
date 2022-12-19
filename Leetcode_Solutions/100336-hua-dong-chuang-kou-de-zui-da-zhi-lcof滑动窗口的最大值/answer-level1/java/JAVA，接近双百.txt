```
    public int[] maxSlidingWindow(int[] nums, int k) {
        if( k <= 1) return nums;

        int[] result = new int[nums.length - k +1];
        // 开始滑动
        for(int i = 0;i<= nums.length-k;i++){
            if(biggest_pos == i-1 ){
                findBiggest(nums,i,k+i-1);
            }else{
                // 判断新来的
                int end = nums[i+k-1];
                if(end >= biggest){
                    biggest = end;
                    biggest_pos = i+k-1;
                }
            }
           result[i] = biggest;
        }
    
        return result;
        
    }


    private void findBiggest(int[] nums,int start,int end){
        biggest = 0;
        for(int i = start;i<= end;i++){
            if(biggest < nums[i]){
                biggest = nums[i];
                biggest_pos = i;
            }
        }
    }

```

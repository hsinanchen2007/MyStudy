双指针应用
```
    public void sortColors(int[] nums) {
        if(nums.length == 0) return ;
        
        int left = 0, right = nums.length-1, i = 0;
        while(i<=right){
            int val = nums[i];
            if(val == 2) swap(nums, i, right--);
            else if(val == 0) swap(nums, i++, left++);
            else i++;
        }
    }
    
    private void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
```

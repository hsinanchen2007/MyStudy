```
private int count(int[] nums, int i, int j, int sum) {
        int l = i; 
        int h = j;
        int res = 0;
        
        while(l < h) {
            if(nums[h] * 2 <= sum) {
                break;
            } 
            while (nums[l] + nums[h] <= sum) {
                l++;
            }
            res += (h - l);
            h--;
        }
        
        return res;
    }
    
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        int res = 0;
        for(int i = len - 1; i > 1; i--) {
            res += (count(nums, 0, i - 1, nums[i]));
        }
        
        return res;
    }
```

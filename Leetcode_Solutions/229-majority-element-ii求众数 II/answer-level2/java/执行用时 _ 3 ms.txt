```
public List<Integer> majorityElement(int[] nums) {
        Arrays.sort(nums);
        int count = nums.length/3;
        int sumtemp = 0;
        List<Integer> res = new ArrayList();
        for(int i = 0 ;i < nums.length ; i++){
            if(i>0 && nums[i] == nums[i-1]){
                sumtemp++;
            }else{
                sumtemp=0;
            }
            if(sumtemp==count){
                res.add(nums[i]);
            }
        }
        return res;
    }
```

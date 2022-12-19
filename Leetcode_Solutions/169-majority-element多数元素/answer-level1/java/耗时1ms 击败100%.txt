## 排序法
```
public int majorityElement(int[] nums) {
    Arrays.sort(nums);
    return nums[nums.length/2];
}
```


## 投票法
```
public int majorityElement(int[] nums) {
        int last=nums[0];
        int count=1;
        for (int i = 1; i < nums.length; i++) {
            if(nums[i]==last)   count++;
            else count--;
            if(count==0){
                i++;
                last=nums[i];
                count=1;
            }
        }
        return last;
    }
```

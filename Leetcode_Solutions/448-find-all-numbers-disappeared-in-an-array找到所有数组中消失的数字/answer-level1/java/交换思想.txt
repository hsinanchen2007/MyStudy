```
public List<Integer> findDisappearedNumbers(int[] nums) {
    List<Integer> res = new ArrayList<>();
     for(int i=0;i<nums.length;i++){
           while(nums[i]!=i+1&&nums[nums[i]-1]!=nums[i]){
             swap(nums,i,nums[i]-1);
          }
    }
    for(int i=0;i<nums.length;i++){
        if(nums[i]!=i+1)
            res.add(i+1);
     }
      return res;
}
public void swap(int[] num,int i,int j){
    int tmp = num[i];
     num[i] = num[j];
     num[j] = tmp;
}
```

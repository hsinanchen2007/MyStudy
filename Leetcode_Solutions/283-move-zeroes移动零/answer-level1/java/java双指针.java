```java
    public void moveZeroes(int[] nums) {
        if (nums == null || nums.length == 1) return;

        int cur=0;
        int next=1;

        while (cur<nums.length&&next<nums.length){
            if (nums[cur]==0){
                if (nums[next]!=0){
                    swap(nums,cur,next);
                }else{
                    next++;
                }
            }else{
                cur++;
                next=cur+1;
            }
        }

    }

    public void swap(int[] nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
```

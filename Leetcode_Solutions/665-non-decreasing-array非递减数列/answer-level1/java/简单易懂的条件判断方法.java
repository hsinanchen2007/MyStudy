这道题目的主要思路是找出原数列中出现递减的位置，因此用一个变量来记录出现递减的次数。如果递减次数大于1，说明至少两个地方的大小关系不符合要求，只改变1个元素是不可能的，返回false。如果递减次数为0，说明原来的数列就满足要求，返回true。
找到递减出现的位置，假设为A>B，那么有pre<=A>B<=pos；如果pre或pos不存在，说明只是在数列头或者尾部出现不正常元素，可以直接修改，返回true。当位于数列中时，就是修改A或者B，那么就必须满足pre<=A<=pos或者pre<=B<=pos才可以，不满足同样返回false。

```
 public boolean checkPossibility(int[] nums) {
        int cnt=0;
        int index=-1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]<nums[i-1]){
                cnt++;
                index=i-1;
            }
            if(cnt>1){
                return false;
            }
        }
        if(cnt==0){
            return true;
        }
        int pre=index-1;
        int A=index;
        int B=index+1;
        int pos=index+2;
        if(pre<0||pos>=nums.length){
            return true;
        }
        return nums[pre]<=nums[B]&&nums[B]<=nums[pos]
                ||nums[pre]<=nums[A]&&nums[A]<=nums[pos];
        
    }
```

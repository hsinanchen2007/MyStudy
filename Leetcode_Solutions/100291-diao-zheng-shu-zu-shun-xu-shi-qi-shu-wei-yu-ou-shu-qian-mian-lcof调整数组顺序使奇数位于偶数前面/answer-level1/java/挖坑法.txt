采用快排中挖坑法，在数组中空出一个坑位，从数组左右两边分别找到第一个偶数、第一个奇数，并将其填入坑中，改变方向继续寻找。

```
代码块
class Solution {
    public int[] exchange(int[] nums) {
        if(nums.length==0)
            return nums;
        int i=0,j=nums.length-1；
        int p=nums[0];       // 以第一个位置为坑，保存其值
        while(i<j){
            while(i<j && nums[j]%2==0)
                j--;
            if(i<j){
                nums[i]=nums[j];
                i++;
            }

            while(i<j && nums[i]%2==1)
                i++;
            if(i<j){
                nums[j]=nums[i];
                j--;
            }
        }
        nums[i]=p;
        return nums;
    }
}
```

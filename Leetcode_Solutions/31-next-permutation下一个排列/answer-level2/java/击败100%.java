从后向前遍历，当遍历到第i个元素出现逆序时（nums[i]>nums[i-1]），选择后面最小的大于nums[i-1]的元素，交换；接下来将nums[i:]从小到大排序，得到的数组就是符合条件的按字典序最小的数组。
```
class Solution {
    public void nextPermutation(int[] nums) {
        boolean flag=true;
        for(int i=nums.length-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                flag=false;
                int k=i;
                for(int j=nums.length-1;j>=i;j--){
                    if(nums[j]>nums[i-1]){
                        k=j;
                        break;
                    }
                }
                int temp=nums[k];
                nums[k]=nums[i-1];
                nums[i-1]=temp;
                //System.out.println(Arrays.toString(nums));
                //将i之后的元素从小到大排列
                for(int m=i;m<nums.length-1;m++){
                    int min=m;
                    for(int n=m+1;n<nums.length;n++){
                        if(nums[min]>nums[n]) min=n;
                    }
                    int temp1=nums[m];
                    nums[m]=nums[min];
                    nums[min]=temp1;
                }
                return;
            }
        }
        if(flag){
            for(int i=0;i<nums.length/2;i++){
                int temp=nums[i];
                nums[i]=nums[nums.length-1-i];
                nums[nums.length-1-i]=temp;
            }
        }
    }
}
```

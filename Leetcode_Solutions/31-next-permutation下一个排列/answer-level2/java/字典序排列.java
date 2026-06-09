```
解题步骤：
1.找到逆序数字段 前面的一个数 标记下标为i
2.交换numsnums[i]和逆序数字段中刚刚大于它的呢个数
3.将逆序数字段顺序
 


class Solution {
    public void nextPermutation(int[] nums) {
        int i=nums.length-2;
                //找出逆序
                while(i>=0&&nums[i]>=nums[i+1]){
                    i--;
                }
                //交换值
                if(i>=0) {
                    for (int j = nums.length - 1; j > 0; j--) {
                        int index = nums[i];
                        if (index < nums[j]) {
                            nums[i] = nums[j];
                            nums[j] = index;
                            break;
                        }
                    }
                }
            //逆序空间反转
            i=i+1;
            for(int j=nums.length-1;i<j;i++,j--){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
    }
    
}
```

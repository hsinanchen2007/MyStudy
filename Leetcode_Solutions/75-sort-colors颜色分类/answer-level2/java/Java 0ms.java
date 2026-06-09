### 解题思路
给定左右边界，从0处开始划分，
1.>1 （2）和右界R处交换并停在原地对交换来的数进行判断（因为右边还没遍历过），R--
2.<1 （0）和左界L处交换，L++，index++
3.=1 （1）经过上面两步判断，当指针触碰到右界时已经将0全部交换到数组左边，2在右边，剩下的1就剩在中间了

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int l = 0;
        int r = nums.length - 1;
        partition(nums,l,r,1);
    }

    private void partition(int[] nums,int l,int r,int num){
        int less = l - 1;
        int more = r + 1;
        int index = l;
        while(index < more){
            if(nums[index] < num){
                swap(nums,++less,index++);
            }else if(nums[index] > num){
                swap(nums,--more,index);
            }else{
                index++;
            }
        }
    }

    private void swap(int[] nums,int i,int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```
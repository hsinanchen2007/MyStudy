解题还要要直接看代码：

class Solution {
    public void nextPermutation(int[] nums) {
        int lengths = nums.length;
        int size = -1;
        for (int i = lengths-1; i >= 0; i--) {
            if(i-1 >= 0 && nums[i-1] < nums[i]){
                size = i-1;
                break;
            }
        }
        //如果没有最大的值了
        if(size == -1){
            for (int i = 0 ,j= lengths-1; i <= j ; i++,j--) {
                int tmp = 0;
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }else{ //处理size后边的数据，重新整理成一个最小数组。
            //找到比size位置大的数中的最小数。
            int tmp = nums[size+1];
            int sizeExchange = size+1;
            for (int i = size+1; i < lengths ; i++) {
                //这里可以优化
                if(nums[i] <= tmp && nums[i] > nums[size]){
                    tmp = nums[i];
                    sizeExchange = i;
                }
            }
            nums[sizeExchange] = nums[size];
            nums[size] = tmp;
            //剩余数据重新重小到大排序
            for (int i = size+1 ,j= lengths-1; i <= j ; i++,j--) {
                int tmp0 = 0;
                tmp0 = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp0;
            }
        }
    }
}
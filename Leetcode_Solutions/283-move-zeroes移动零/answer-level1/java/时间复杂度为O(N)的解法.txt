class Solution {
    // 先将非0值全部移动到最左侧。
    // 移动一个0，后面的数需要移动数为1，所以移动n个0，移动数为n
    // 最后再根据cnt（移动0的数），往最右侧添加0
    public void moveZeroes(int[] nums) {
        // 需要移动的步数
        int cnt = 0;
        for(int i = 0; i < nums.length; i++) {
            // 如果当前值为0，移动值加1
            if(nums[i] == 0)
                cnt++;
            else 
                nums[i - cnt] = nums[i];
        }

        for(int i = nums.length - cnt; i < nums.length; i++)
            nums[i] = 0;
    }
}
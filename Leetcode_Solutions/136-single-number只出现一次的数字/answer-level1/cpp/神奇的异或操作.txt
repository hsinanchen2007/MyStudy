1.两个相同的数求异或等于0；
2.任何数与0求异或等于它本身；
3.异或运算具有可交换性；
因此：将数组中所有元素求异或的结果就是数组中只出现一次的数字。

    int singleNumber(vector<int>& nums) {
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            result^=nums[i];
        }
        return result;
    }
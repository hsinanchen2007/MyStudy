bool containsDuplicate(vector<int>& nums)
{
    int lens = nums.size();
    for(int i = 0; i < lens; i++){
        while (nums[i] != i){       
            if(nums[i] == nums[nums[i]]){
                return true;
            }
            swap(nums[i],nums[nums[i]]);
        } 
    }
    return false;
}

报错：
AddressSanitizer: heap-buffer-overflow on address 0x602000000134 at pc 0x0000004053ea bp 0x7ffc05325990 sp 0x7ffc05325980

不知道为什么存在内存溢出错误，leetcode其他题目使用上述方法，并没有出现内存溢出，因此应该是样本的问题，不知道对不对
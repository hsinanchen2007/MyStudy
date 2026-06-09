public class Solution {
    public int FirstMissingPositive(int[] nums) {
        
        int n = nums.Length;
        int index = 0;
        //count记录不符合预期区间值的元素个数
        int count = 0;
        //从数组第一个成员开始依次往后检查值是否在预期区间内（1 - nums.Length）
        while(index < n - count) {
            //如果当前成员值不在预期区间，则把当前成员值与最后一个成员互换，最后需要监测的数组成员减少一位
            if(nums[index] <= 0 + index || nums[index] > nums.Length) {
                nums[index] = nums[n - 1 - count];
                count++;
            }
            //经过第一层判断，当前nums[index]的值一定在预期区间内，如果当前监测的元素的值不等于当前监测序号，例如第一个元素的值不等于1 而等于3，那就把第             //3个元素的值直接改成3 把第3个元素的原来值赋予第一个元素再次重新监测第一个元素
            else{
                //如果第N个元素值正好等于N 则开始监测第 N + 1 号元素
                if(nums[index] == index + 1) {
                    index++;  
                } 
                //如果第index元素的值val与第val个元素的值相同，则直接把其中一个元素的值改到不符合要求值的区间外 避免两个相同值元素不停循环的互换值而导致                 //成了死循环
                else{
                    int val = nums[index];
                    if(nums[val - 1] != nums[index]){
                        nums[index] = nums[val - 1];
                        nums[val - 1] = val;
                    }
                    else{
                        nums[index] = 0;
                    }         
                }
            }
        }
        return index + 1;
    }
}
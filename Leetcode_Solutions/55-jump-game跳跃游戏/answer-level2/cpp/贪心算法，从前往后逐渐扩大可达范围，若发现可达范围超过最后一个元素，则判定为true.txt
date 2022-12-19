


class Solution {
public:
bool canJump(vector<int>& nums) {
    size_t sizeOfNums = nums.size();
    size_t lastCount = sizeOfNums - 1;
    size_t index = 0;
    size_t availableMaxIndex = 0;
    //逐步扩大范围，步步紧逼。最终范围能超过就是true，无法超越就是false
     do{
        if(availableMaxIndex >= lastCount)
        {
            return true;
        }
        int currentValue = nums[index];
            int nextValue = (int)index + currentValue;
            if (nextValue > availableMaxIndex) {
                availableMaxIndex = nextValue;
            }
        index++;
     }while (index <= availableMaxIndex);
    return availableMaxIndex >= lastCount;
}
};
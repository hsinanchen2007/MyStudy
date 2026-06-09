数组长度小于3的情况下肯定可以只改变一个元素就将其变为非递减数列。
         当数组长度大于等于3时，先对索引为0,1,2的前三个数进行判断：如果nums[0]>nums[1]>nums[2],这种情况返回false；
如果nums[0]>nums[1]&&nums[1]<=nums[2],令nums[0]=nums[1]，同时断点数+1;(这样做是为了处理三个数中第一个数大于第二个数的情况)
         接下来对连续三个数进行判断：如果nums[i]>nums[i+1]说明出现断点（经过上面的处理后，此时肯定满足nums[i-1]<=nums[i]），
需要更改元素：比较nums[i-1]和nums[i+1]大小来更改：nums[i-1]<=nums[i+1]?nums[i]=nums[i-1]:nums[i+1]=nums[i];
         如果程序最后的count大于1，说明更改超过一个元素，返回false；否则返回true。

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<3){
            return true;
        }
        int count = 0;
        if(nums[0]>nums[1]&&nums[1]>nums[2]){
            return false;
        }
        if(nums[0]>nums[1]&&nums[1]<=nums[2]){
            count++;
            nums[0]=nums[1];
        }
        for(int i=1;i<=nums.size()-2;i++){
            if(nums[i]>nums[i+1]){
                count++;
                nums[i-1]<=nums[i+1]?nums[i]=nums[i-1]:nums[i+1]=nums[i];
            }
        }
        if(count>1){
            return false;
        }
        else{
            return true;
        }
    }
};

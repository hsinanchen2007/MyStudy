![屏幕快照 2019-10-04 下午5.57.34.png](https://pic.leetcode-cn.com/b44695e584f907a159f057c90db3332befc0b70d239560e4de7f0cc51c392cfa-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-10-04%20%E4%B8%8B%E5%8D%885.57.34.png)
取最后一个元素，若从该元素开始之后元素都是递减，则游标往前走，直到遇到第一个不是递减的元素，将该元素之后的序列逆序，然后找出第一个大于该元素的元素，与之交换位置即可。
```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int head = nums.size()-1;
        while(head>=0&&biggerstPermutaution(nums,head)) head--;
        head++;
        revserseNums(nums,head);
        if(head!=0){
            int k = head-1;
            while(nums[k]>=nums[head]) head++;
            swap(nums[head],nums[k]);
        }
    }
    bool biggerstPermutaution(vector<int> nums,int start){
        for (int i = start; i < nums.size()-1; ++i) {
            if(nums[i]<nums[i+1]) return false;
        }
        return true;
    }
    void revserseNums(vector<int> &nums,int start){
        int i =start,j=nums.size()-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};
```

刚开始mid的选择出了点问题  前面几道题都是int mid=left+(right-left+1)/2;
结果这次在边界上出现了错误  如[1,3] 4的时候 while之后的选择插入顺序不能出现错误 否则先判断一次target<=nums[2]的情况导致程序错误
![TIM图片20200325181024.png](https://pic.leetcode-cn.com/70cdddcbefbba977c5e5759305d61fec372262e9208e892567a494288ecdaa18-TIM%E5%9B%BE%E7%89%8720200325181024.png)

```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;int right=n-1;
        while(left<right){
            int mid=left+(right-left+1)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        if(target>nums[right]){
            return right+1;
        }
        if(target<=nums[left]){
            return left;
        }
        return right;

    }
};
```
mid=left+(right-left)/2;的时候代码
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;int right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        if(target<=nums[left]){
            return left;
        }
        if(target<=nums[right]){
            return right;
        }
        return right+1;

    }
};
```

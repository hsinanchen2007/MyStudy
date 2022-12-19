### 解题思路
先确定旋转点的数组下标。
根据target可能落在的区间进行二分查找。
细节在代码里的注释。
### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)//若数组为空，返回-1
            return -1;
        if(nums.size() == 1)//若数组只有一个元素，判断它是否是target
            return nums[0] == target? 0 : -1;
        //通过二分法查找旋转点，结果为前半部分升序最大下标。注 数组有可能为[1,3]这样的只有升序的前半部分
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left + 1) / 2;//+1是希望mid被分到右边
            if(nums[mid] < nums[left])
                right = mid - 1;
            else
                left = mid;
        }
        //循环结束，left==right 若只有升序的前半部分数组，则left=right=nums.size()-1
        int res = -1;
        int rotIdx = left;//旋转点
        if(nums[rotIdx] == target)
            return rotIdx;
        //target在数组开头到旋转点之间
        else if(nums[rotIdx] > target && target >= nums[0])
            res = binarySearch(nums, 0, rotIdx, target);
        //target比第一个元素小，且旋转点后面还有数（这些数字必然小于nums[0]）
        else if(target < nums[0] && rotIdx + 1 <= nums.size() - 1)
            res = binarySearch(nums, rotIdx + 1, nums.size() - 1, target);
        return res;
    }
private:
    //对升序的数组进行二分查找
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target)
                right = mid;
            else 
                left = mid + 1;
        }
        if(nums[left] == target)
            return left;
        else
            return -1;
    }
};
```
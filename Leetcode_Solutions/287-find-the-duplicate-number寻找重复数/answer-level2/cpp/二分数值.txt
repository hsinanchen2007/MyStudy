### 解题思路
解法1
    （1）首先想到的是hash表去重，unordered_set插入元素前find一下查看元素是否已经存在，存在的话则这个元素就是答案，时间复          杂度是O(1)，空间复杂是O(n)
    （2）借助一个长度为nums中元素最大值的数组cnt，cnt[nums[i]]统计值为nums[I]的元素个数,时间复杂度O（n）,空间复杂度O(n)

解法2
时间复杂度O（nlog2n）
空间复杂度O（1）
### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        // <号，答案一般写在while循环外头，因为循环退出right和left指向同一个元素（一般这个就是答案，不可再二分）
        while(left < right) {
            //元素个数是奇数时，mid指向中间那个元素
            //元素个数是偶数
            //    （1）mid = left + (right - left)/2，mid指向中点偏左的元素，比如【1,2,3,4 】mid指向元素2
            //    （2）mid = left + (right - left+1)/2，mid指向中点偏右的元素，比如【1,2,3,4】mid指向元素3
            //所以划分到最后如果剩下两个元素时
            //      （1）如果mid = left + (right - left)/2【此时mid是指向两个元素中的第一个元素】，left = mid+1，                              right = mid，不然right和left最后不能指向同一元素
            //      （2）如果mid = left + (right - left+1)/2【此时mid是指向两个元素中的第二个元素】，则left = mid，                            right = mid-1，不然right和left最后不能指向同一元素
            int mid = left + (right - left)/2;
            int count = 0;
            //二分的是元素的大小，和平常的二分下标不一样
            for(int i = 0; i < nums.size(); ++i) {
                //计算大于中间值的数有多少个
                if(nums[i] <= mid) {
                    count++;
                }
            }
            if(count > mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
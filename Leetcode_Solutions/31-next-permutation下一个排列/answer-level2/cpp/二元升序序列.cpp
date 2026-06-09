思路：
第一步：从左到右找到最后一个升序2元序列，如果找不到（也就是全部为降序序列），则该给定序列不存在更大序列，就返回重排的升序序列；如果找到了，则交换该2元序列的两个元素。
例如：[2,6,4,5,3]，从左到右的2元升序序列为：[2,6],[2,4],[2,5],[2,3][4,5],最后一个为[4,5]
第二步：假设找到的最后一个升序二元序列的索引分别为left，right，将left+1开始的元素进行升序排序后，就是我们需要找的邻近序列。

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = 0;
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[j] > nums[i]) {
                    left = i;
                    right = j;
                }
            }
        }
        if (left == right) {
            sort(nums.begin(), nums.end());
        } else {
            swap(nums[left], nums[right]);
            sort(nums.begin() + left + 1, nums.end());
        }
    }
};
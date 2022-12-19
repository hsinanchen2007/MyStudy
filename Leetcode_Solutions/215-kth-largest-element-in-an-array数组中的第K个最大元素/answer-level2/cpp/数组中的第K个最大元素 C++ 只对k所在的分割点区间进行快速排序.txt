### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0,nums.size()-1,k);
    }
    
    // nums：未排序数组 left：快速排序区间左边界下标 right：快速排序区间右边界下标
    int quickSelect(vector<int> &nums,int left, int right, int k) {
        // 如果left等于right，快排区间只有一个元素，排序结束
        if (left == right) return nums[left];
        // 进行1轮快排，然后返回排序区间的分割点，分割点左边的元素都比分割点的元素小，右边的元素都比分割点的元素大。
        int pos = partition(nums,left,right);
        // 如果分割点就是k
        if (pos == nums.size()-k) {
            return nums[pos];
        }
        // 如果分割点在k的左边，对区间[pos+1，right]进行快排，另一边不需要完成排序
        else if (pos < nums.size()-k) {
            return quickSelect(nums,pos+1,right,k);
        }
        // 如果分割点在k的右边，对区间[left，pos-1]进行快排，另一边不需要完成排序
        return quickSelect(nums,left,pos-1,k);
    }
    
    // 进行1轮快排，然后返回排序区间的分割点，分割点左边的元素都比分割点的元素小，右边的元素都比分割点的元素大。
    int partition(vector<int> &nums, int left, int right) {
        // 设置随机数种子
        srand(time(nullptr));
        // 生成[left,right]范围内的随机数索引
        int pivot_index = rand() % (right-left+1) + left;
        // 分割点元素pivot
        int pivot = nums[pivot_index];
        // 交换分割点元素pivot和最后一个元素的位置
        swap(nums[pivot_index], nums[right]); 
        // i为循环次数，j为遍历后确定下来的分割点位置，比分割点小的元素都会移动到j前面
        int i, j=left;
        for (i=left; i<right; i++) {
            if (nums[i] < pivot) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        // 交换num[j]和pivot的位置，此时j即为pivot最终位置
        swap(nums[right], nums[j]);
        return j;
    }
};


#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int left, int right) {
    srand(time(nullptr));
    int pivot_index = rand() % (right-left+1) + left;
    int pivot = nums[pivot_index];
    swap(nums[pivot_index], nums[right]); 
    int i, j=left;
    for (i=left; i<right; i++) {
        if (nums[i] < pivot) {
            swap(nums[i],nums[j]);
            j++;
        }
    }
    swap(nums[right], nums[j]);
    return j;
}

int quickSelect(vector<int> &nums,int left, int right, int k) {
    if (left == right) return nums[left];
    int pos = partition(nums,left,right);
    if (pos == nums.size()-k) {
        return nums[pos];
    }
    else if (pos < nums.size()-k) {
        return quickSelect(nums,pos+1,right,k);
    }
    return quickSelect(nums,left,pos-1,k);
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums,0,nums.size()-1,k);
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    cout << findKthLargest(nums, 2) << endl;
}





```
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void heapSort(vector<int>& a, int pos, int size) {
        int temp = a[pos];
        for (int i = 2*pos+1; i < size; pos = i, i = 2*i+1) {
            if(i+1 < size && a[i] > a[i+1]) {
                i++;
            }
            if(temp > a[i]) {
                a[pos] = a[i];
            } else {
                break;
            }
        }
        a[pos] = temp;
    }
    //维护一个k大小的小顶堆
    int findKthLargest(vector<int>& nums, int k) {
        //从最后一个非叶子节点开始调整
        for (int i = (k-1)/2; i >= 0; i--) {
            heapSort(nums, i, k);
        }
        for (int i = k; i < nums.size(); i++) {
            if(nums[0] < nums[i]) {
                nums[0] = nums[i];
                heapSort(nums, 0, k);
            }
        }
        return nums[0];
    }
};
```
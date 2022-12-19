### 解题思路
1. 建立最大堆
2. 输出(与堆中最后一个元素交换,可理解为删除)k-1个堆顶元素之后的新堆顶元素即为所求

### 代码

```cpp
class Solution{
public:
    //nums[0] 保留作为哨兵
    void adjust_down(vector<int>&nums, int k, int len){
        nums[0] = nums[k];
        for(int i=2*k;i<=len;i*=2){
            if(i+1<=len && nums[i]<nums[i+1])
                i++;
            if(nums[i] < nums[0]) break;
            else{
                nums[k] = nums[i];
                k = i;
            }
        }
        nums[k] = nums[0];
    }

    void build_heap(vector<int>& nums, int len){
        for(int i=len/2;i>0;i--){
            adjust_down(nums, i, nums.size()-1);
        }
    }

    void swap(int& num1, int& num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    int findKthLargest(vector<int>& nums, int k) {
        nums.insert(nums.begin(),-1);
        int len = nums.size()-1;
        build_heap(nums, len);
        while(--k){
            swap(nums[1], nums[len]);
            adjust_down(nums, 1, --len);
        }
        return nums[1];
    }
};

```
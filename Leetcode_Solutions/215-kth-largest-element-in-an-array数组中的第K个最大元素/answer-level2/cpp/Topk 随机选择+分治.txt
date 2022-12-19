### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void swap(int &a, int &b)
    {
        if(a == b) return;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    //分割/划分,小的在前面，大的在后面
    int CutVector(vector<int>& nums, int left, int right)
    {
        srand((int)time(0));
        int rIndex = rand() % (right - left + 1) + left;
        int cut = nums[rIndex];
        //将它移动到尾部
        swap(nums[right], nums[rIndex]);
        int index = left;
        for(int i = left; i < right; i++)
        {
            if(cut >= nums[i])
            {
                swap(nums[i], nums[index]);
                index++;
            }
        }

        swap(nums[right], nums[index]);
        return index;
    }
    //选择
    int selectSort(vector<int>&nums, int left, int right, int target)
    {
        if(right == left) return nums[left];

        int cutIndex = CutVector(nums, left, right);

        if(cutIndex == target) return nums[cutIndex];
        else if(cutIndex > target) return selectSort(nums, left, cutIndex - 1, target);
        else return selectSort(nums, cutIndex + 1, right, target);
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() <= 0) return -1;
        //方法1 使用堆排序时间复杂度为 nlogk
     /*   priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 0; i < nums.size(); i++)
        {
            q.push(nums[i]);
            if(q.size() > k)
                q.pop();
        }

        return q.top();*/
        //方法2 选择快排（随机+隔离）
        //随机选择，划分，比较那边，进行排序,转换为第size-k小的数
        return selectSort(nums, 0, nums.size() - 1, nums.size() - k );
    }
};
```
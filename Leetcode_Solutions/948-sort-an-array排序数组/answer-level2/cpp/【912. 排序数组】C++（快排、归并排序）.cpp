### 解题思路
考察基本的数组排序算法
使用快速排序和归并排序
快排：
![image.png](https://pic.leetcode-cn.com/0b25de6a7cb292e67c1a9c77b178a3b2a641b23dbac01dcfaf5b567c47173a50-image.png)
归并：
![image.png](https://pic.leetcode-cn.com/2dc1415dcd80eca0228bd0bdef06e71aeca35fc1027704dcd18da0e09a62e329-image.png)

### 代码

```cpp []
class Solution {
    // 快排
    private:
    void fast_sortArray(vector<int>& nums, int left, int right){
        if(left>=right)
            return;
        int base = nums[left], tmp;
        int i = left, j = right;
        // int flag = 0;
        while(i<j){
            while(i<j && nums[j]>=base)
                j--;
            while(i<j && nums[i]<=base)
                i++;
            if(i<j){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        nums[left] = nums[i];
        nums[i] = base;
        // for(int num:nums)
        //     cout<<num<<"\t";
        // cout<<endl;
        fast_sortArray(nums, left, i-1);
        fast_sortArray(nums, i+1, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int right = (int)nums.size()-1;
        fast_sortArray(nums, 0, right);
        return nums;
    }
};
```

```cpp []
class Solution {
    // 归并排序
    vector<int> tmp;
private:
    void merge_sortArrary(vector<int>& nums, int left, int right){
        if(left>=right)
            return;
        int mid = (left+right)/2;
        merge_sortArrary(nums, left, mid);
        merge_sortArrary(nums, mid+1, right);
        int cnt = 0;
        int i = left, j = mid+1;
        while(i<=mid && j<=right){
            if(nums[i]<=nums[j])
                tmp[cnt++]=nums[i++];
            else
                tmp[cnt++] = nums[j++];
        }
        while(i<=mid)   tmp[cnt++] = nums[i++];
        while(j<=right)   tmp[cnt++] = nums[j++];
        for(i = 0; i<right-left+1; i++)
            nums[left+i] = tmp[i];
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int len = (int)nums.size();
        tmp.resize(len);
        merge_sortArrary(nums, 0, len-1);
        return nums;
    }
};
```

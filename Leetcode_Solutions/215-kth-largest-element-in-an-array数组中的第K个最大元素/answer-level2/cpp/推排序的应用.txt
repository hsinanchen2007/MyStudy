### 解题思路
趁此用堆排序就是重新复习下之前学的知识了。
评论区还有种改造快排的算法，在找出现次数最多（超过一半）也有应用。

### 代码

没有用函数分离里面的两个函数功能。
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = nums.size() / 2 - 1; i >= 0; i--)
        {//建立最大堆
            int t = nums[i];
            int j = i;
            while (1){
                int l = j * 2 + 1;
                int r = l + 1;
                if (l >= nums.size())
                    break;
                if (r < nums.size() && nums[l] < nums[r])
                    l = r;
                if (t < nums[l])
                {
                    nums[j] = nums[l];
                    j = l ;            
                }
                else
                    break;
            }
            nums[j] = t;
        }
        //每次去顶堆（最大值）
        int s = nums.size() - 1;
        for (int j = 1; j < k; j++)
        {
            swap(nums[0], nums[s]);//首尾交换
            int m = 0;
            int e = nums[0];
            while (m < s) {
                int l = m * 2 + 1;
                int r = l + 1;
                if (l >= s)
                    break;
                if (r <  s && nums[l] < nums[r])
                    l = r;
                if (e < nums[l])
                {
                    nums[m] = nums[l];
                    m = l ;
                }
                else
                    break;
            }
            nums[m] = e;
            s--;
        }
        return nums[0];
    }
};
```
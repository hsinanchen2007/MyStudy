![image.png](https://pic.leetcode-cn.com/468679191cd8895f15f4755591833e0bf3422e5d618e2f8f5e6fefe807aee2dc-image.png)


### 解题思路
个人感觉就是找规律，如下
4 5 
5 4

3 4 5
3 5 4
4 3 5
4 5 3

2 3 4 5 
2 3 5 4
2 4 3 5
2 4 5 3.......

不难发现每一次迭代都是比它少一个数字的结果的重复，那么一但替换开头的数字，我们后面后面的数字就需要反转，来回归到最小的情况

伪代码
1.从后向前，找到第一个非递增数字
2.找到就开始在找后面第一个比当前非递增数字大的数字
3.如果没有找到那么直接反转 因为已经是最大的了
4.交换位置且反转剩下数列



### 代码

```cpp
class Solution {
public:
    void reverse(vector<int>& nums, int begin, int end){
        while (begin < end){
            int temp = nums[begin]; nums[begin] = nums[end]; nums[end] = temp;
            begin++; end--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) return;

        int i = nums.size() - 1;

        while(i > 0){
            if(nums[i -1] >= nums[i])
                i--;
            else
                break;
        }

        if(i == 0){
            reverse(nums, 0, nums.size() -1); return;
        }

        int p = nums.size() - 1;

        while(p > i - 1){
            if(nums[p] > nums[i - 1])
                break;
            p--;
        }

        int temp = nums[p]; nums[p] = nums[i-1]; nums[i-1] = temp;

        reverse(nums, i, nums.size() - 1);
    }

};
```
分析： 题目点名是滑动窗口，但此题考察点不仅仅是滑动窗口，还要找寻当前滑动窗口里的最大值。找k个数的最大值很简单，哪怕用遍历方法。但是在滑动窗口中需要分两种情况：

- 上一个滑动窗口的最大值在窗口最左边，这时需要重新遍历下一个窗口，找下一个窗口的最大值；
- 上一个滑动窗口的最大值不在窗口最左边，这时仅需要将下一个窗口的最右边的值与上一个窗口的最大值比较，进而更新最大值。
代码如下：

```
class Solution {
public:
    int findMax(vector<int>&nums, int left, int right){
        int max = nums[left];
        for (int i = left + 1; i <= right; i++){
            if (nums[i] > max){
                max = nums[i];
            }
        }
        return max;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
	    if (k > nums.size()||nums.size() == 0){
		    return res;
	    }
        int left = 0;
        int right = k - 1;
        int curMax = 0;
        int subMax = 0;
        int i = left;
        curMax = findMax(nums, left, right);
        res.push_back(curMax);
        while (right < nums.size()-1){
            right++;
            left++;
            if (curMax == nums[left-1]){
                subMax = findMax(nums, left, right);
            }
            else{
                subMax = curMax;
            }
            curMax = subMax>nums[right] ? subMax : nums[right];
            res.push_back(curMax);
        }
        return res;
        }
};


```

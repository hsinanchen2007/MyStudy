![捕获.PNG](https://pic.leetcode-cn.com/3b239df3b9d752b89676d461826589957b7c16870509c60aec0ff6818be3df32-%E6%8D%95%E8%8E%B7.PNG)
这是一道很有意思的问题，难点在于空间复杂度的控制。可能有些coder一开始没有明白题意，先做下简单解释。
正常的无缺失的数组应该为：
[1,2,3,4,5,6,7,8,......]
即按照递增的正整数排列下去，如果题目所给的输入数组如下：
[4,2,2,1,-1,9,8,10,-9]
该数组中，第一个缺失的正整数为3，因为数组中包含1，2，缺失了3。于是返回值应该为3。

一个很直接的思路是，将输入数组排序，从大于0的整数开始数，看哪一个数出现缺失，这种方式需要提前排序，时间复杂度大于O(n)。为此，我们想到使用哈希表，用空间换时间。设输入数组的大小为n，则缺失的整数最大为n+1。我们可以在遍历数组时，将每个出现的int作为哈希表的key，将value值更新为true。最后再遍历哈希表，找到第一个value值为false的key,这个key就是返回值。这种算法只要求O(n)的时间复杂度，但额外需要O(n)的空间复杂度。因此，我们需要一个更好的算法。

这就是哈希表的变形。题目要求我们使用常数大小的额外空间，则这是一个in place的算法，需要原地改变数据的值，不开辟额外空间。于是我们需要在原数组上进行记录，思路如下：
1. 预处理数组，将数组中小于等于0的数和大于n的数统一替换为1。（需对返回值本为1的情况做预先判断）
2. 遍历数组，遇到元素element，将index = nums[element]处的元素变为相反数，即变为负数（前提是原来为正数，作为一个标记，表明这个位置对应的index整数在数组中出现过，这一做法不会改变原数组核心信息，但注意下次遇到element要取绝对值）。
3. 再次遍历数组，遇到第一个为正数时，它的下标即为要返回的整数。若全为负数，返回n+1;

代码如下：
```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //return 0;
        int n = nums.size();
        bool flag = true;
        for(int i=0; i<n; i++){
            if(nums[i] == 1) flag = false;
        }
        if(flag) return 1;
        for(int i=0; i<n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }
        for(int i=0; i<n; i++){
            int pos = nums[i] > 0 ? nums[i] : (-nums[i]);
            nums[pos-1] = nums[pos-1] > 0 ? (-nums[pos-1]) : nums[pos-1];
        }
        //find the fist positive index
        int ret = n+1;
        for(int i=0; i<n; i++){
            if(nums[i] > 0) return i+1;
        }
        return ret;
    }
};
```

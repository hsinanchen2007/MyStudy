基本思路如下：
准备n个桶，遍历数组，遍历到nums[i]时，若nums[i]==k，则判断第k个桶是否为空，如果非空，则说明k就是重复的元素，否则将其放入第k个桶。
如果开辟大小为n的数组作为桶，则不满足题目中关于空间复杂度为O(1)的要求，所以需要采取与41题类似思路，利用交换操作在nums数组上实现原址桶排序。
具体实现方法如下：
遍历nums，当迭代到nums[i]时，记k=nums[i]，交换nums[i]与nums[k-1]，重复该过程，直到nums[i]=i+1，令i=i+1，迭代下一个元素。
```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            while(nums[i] != i + 1){
                int tmp = nums[i];
                if(nums[i] == nums[tmp - 1]) return nums[i];
                nums[i] = nums[tmp - 1];
                nums[tmp - 1] = tmp;
            }
        }
        return 0;
    }
};
```

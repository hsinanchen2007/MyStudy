用队列来存放数组中0元素的索引。每当遇到一个0元素时，将这个0元素的索引push进队列。当遇到第一个不为0的元素时，马上将该元素和第一个0元素交换位置，并更新队列（将队列首pop出来，并存到队列尾部），这样可以保证剩下的非零元素的相对位置不变。
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> zero;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zero.push(i);
            if(!zero.empty()&&nums[i]!=0)
            {
                swap(nums[zero.front()],nums[i]);
                zero.pop();
                zero.push(i);
            }
        }
    }
};
```



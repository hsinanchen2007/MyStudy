1. 初始化0的最后元素指针p0=-1,2的第一个元素指针p2=nums.size(),cur指针cur=0
2. 若cur位置元素为0，且不是p0的下一个元素，交换nums[++p0]与nums[cur]
3. 若cur位置元素为2，且不是p2的前一个元素，交换nums[--p2]与nums[cur]
4. 否则cur++
``` C++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty())
            return ;
        int p0=-1,cur=0,p2=nums.size();
        while(cur<p2)
        {
            int temp;
            if(nums[cur]==0&&cur-p0!=1)
            {
                temp=nums[++p0];
                nums[p0]=nums[cur];
                nums[cur]=temp;
            }
            else if(nums[cur]==2&&p2-cur!=1)
            {
                temp=nums[--p2];
                nums[p2]=nums[cur];
                nums[cur]=temp;
            }
            else
                cur++;
            
        }
        
    }
};
```
【思路】
    一个指针k标识当前数组中有效元素的下标
    一个指针i标识遍历到当前元素的下标
    每次将当前遍历的元素与有效元素的最后两个进行比较：
    1.若三者相同，则跳过不处理当前元素
    2.三者不同，判断当前遍历元素的小标与有效元素的小标是否相同：
        2.1不同则将当前元素赋值给有效元素下标位置
        2.2相同不做处理
    3.更新有效元素小标的值


【C++代码】
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int k=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(k>1 && nums[i]==nums[k-1] && nums[i]==nums[k-2])
                continue;
            if(i!=k)
                nums[k]=nums[i];
            k++;
        }
        return k;
    }
}
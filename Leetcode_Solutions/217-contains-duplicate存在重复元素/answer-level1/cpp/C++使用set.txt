   

将vector中的数放入set中，再根据长度判断是否有重复元素
bool containsDuplicate(vector<int>& nums) //存在重复元素
{
    set<int> s;
    for(int i=0;i<nums.size();i++)
    {
        s.insert(nums[i]);
    }
    if(s.size()==nums.size()) return false;
    else return true;
}
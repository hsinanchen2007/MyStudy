### 解题思路
和划分K个子解一样，本题就是划分4个子集。先排除不是4的倍数或者单值大于单边值的情况，然后去掉直接等于边长的数字，最后通过递归算就行了。递归部分思想很简单，就是考虑将一个个数往合适的子集插入，这么判断合适呢，我数据用完了肯定合适了。

### 代码

```cpp
class Solution {
public:
bool judge(vector<int>groups,vector<int> &nums,int index,int len){
    if(index<0)         return true;
    int temp=nums[index--];
    for(int i=0;i<groups.size();i++){
        if(groups[i]+temp<=len){                                   //尝试加失败回退
            groups[i]+=temp;
            if(judge(groups,nums,index,len))   return true;
            groups[i]-=temp;
        }
        if(groups[i]==0) break; //此次大大减少了无用计算
    }
    return false;
}
    bool makesquare(vector<int>& nums) {
        if(nums.size()<=3) return false;
        int count=0;
        for(auto i:nums) count+=i;
        cout<<count<<endl;
        if(count%4!=0) return false;
        int len=count/4;
        int k=4;
        int index=nums.size()-1;
        for(auto i:nums)
        {
            if(i>len) return false;
            if(i==len){
                k--;
                index--;
            }
        }  
        if(k==0) return true;
        sort(nums.begin(),nums.end());
        vector<int> groups(k,0);
        return judge(groups,nums,index,len);
    }
};
```
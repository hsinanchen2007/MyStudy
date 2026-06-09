### 解题思路
参考别人，做个记录

### 代码

```cpp
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int len = nums.size();
        if(len < 4) return false;
        
        int sum = 0;
        for(int &i : nums)  
            sum += i;
        /*因为用到每一根火柴，所以和不是4的倍数直接排除*/
        if(!sum%4) return false;     
        /*边长*/
        int target = sum/4;
        /*模拟4个边*/
        vector<int>temp(4,0);
        /*排序剪枝*/
        sort(nums.begin(),nums.end(),cmp);
        return help(0,target,nums,temp);
    }
    /*pos为正在处理的nums数组下标*/
    bool help(int pos,int target,vector<int>&nums,vector<int>&temp){
        /*结束遍历的条件*/
        if(pos >= nums.size())
            return temp[0]==target&&temp[1]==target&&temp[2]==target&&temp[3]==target?true:false;
        
        /*组合4个边接近targrt*/
        for(int i = 0;i < 4;i++){
            if(temp[i] + nums[pos] > target)
                continue;
            
            temp[i] += nums[pos];
            if(help(pos+1,target,nums,temp))
                return true;
            /*回溯*/
            temp[i] -= nums[pos];
        }
            return false;
    }
    static bool cmp(int &a,int &b){    //因为普通成员函数含有额外参数this指针，参数不匹配，
                                       //所以用静态成员函数
        return a>b; 
    }
};
```
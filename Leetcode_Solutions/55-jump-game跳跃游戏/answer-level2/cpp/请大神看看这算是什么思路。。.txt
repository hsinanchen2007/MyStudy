大概分析了一下，路径中每一点都为正数的话一定能到终点，所以就找步数是0的点，再判断该点之前的数值能否满足越过该点的条件，总的遍历一遍就可解决。
```
代码块class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        int temp=1;
        if(size==1) return true;

        if(nums[0]==0) return false;

        for(int i = size-1;i>0;)
        {
            if(nums[i-1]==0)
            {
                while(nums[i-1-temp]<=temp){
                    
                    temp++;
                    if(i-1-temp<0)
                        return false;
                }
                i=i-1-temp;
                temp=1;
            
            }else 
                i--;
            
        }
        return true;
}
};
```

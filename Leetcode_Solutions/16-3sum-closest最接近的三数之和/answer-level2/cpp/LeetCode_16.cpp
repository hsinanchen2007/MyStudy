### 解题思路
此处撰写解题思路:与三数之和解法类似：排序加双指针
详见代码：

### 代码

```cpp
class Solution {
public:
    /*注意本题与三数之和的区别和联系*/
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());  /*先对数组进行排序*/
        int closer_num; /*记录最接近目标值的数*/
        int max=INT_MAX;
        int n=nums.size();
        if(n==3)
            return nums[0]+nums[1]+nums[2]; /*数组中只存在三个数的情况*/
        for(int i=0;i<n-2;++i){
            if(i>0&&nums[i]==nums[i-1]) continue;   /*去重*/
            int tmp=nums[i];
            int left=i+1,right=n-1;
            while(left<right){
                int dis=nums[i]+nums[left]+nums[right]-target;      
                /*fabs(dis)为和与目标值的距离*/
                if(fabs(dis)<max){  /*若dis绝对值小于max,则更新max和closer_num*/
                    max=fabs(dis);
                    closer_num=dis+target;
                }   
                if(dis<0)   /*若dis小于0，则左指针右移来增大dis*/
                    ++left;
                else if(dis>0)  /*若dis大于0，则右指针左移来减小dis*/
                    --right;
                else{
                    return target;  /*若dis等于0，则直接返回目标值，跳出循环*/
                    break; 
                }  
            }
        }
        return closer_num;
    }
};
```
### 解题思路
每个数遍历一遍，找到前边界，再倒序遍历一遍，找到左边界
### 代码

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int a=0,b=0,minn=-1,maxx=-1;
        bool w=false; 
        for(int i=1;i<nums.size();i++){
            if(!w && nums[i-1]>=nums[i]){
                minn=nums[i];
                w=true;
            }else if(w && minn>nums[i]){
                minn=nums[i];
            }
        }
        cout<<"minn:"<<minn<<endl;
        if(minn!=-1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]>minn){
                    a=i;
                    cout<<"a:"<<a<<endl;
                    break;
                }
            }
        }
        w=false;
        for(int i=nums.size()-2;i>=0;i--){
            if(!w && nums[i+1]<=nums[i]){
                maxx=nums[i];
                w=true;
            }else if(w && maxx<nums[i]){
                maxx=nums[i];
            }
        }
        cout<<"maxx:"<<maxx<<endl;
        if(maxx!=-1){
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]<maxx){
                    b=i;
                    cout<<"b:"<<b<<endl;
                    break;
                }
            }
        }
        if(b-a==0){
            return 0;
        }else if(minn==maxx){
            return 0;
        }
        return b-a+1;
    }
};
```
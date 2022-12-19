### 解题思路
C++版本的双指针算法，可以配合视频看双指针，简单明了，我也是看视频后才写出来的。但感觉这个更符合视频的意思，这里的a+b=-c的c也是如果跟上一个c一样那就算重复了。

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        for(int i=0;i<len-2;++i){
            if(i==0||(i>0&&nums[i]!=nums[i-1])){ //
                int low=i+1;
                int height=len-1;
                while(low<height){
                    if(nums[low]+nums[height]>-nums[i]){
                        height--;
                    }else if(nums[low]+nums[height]<-nums[i]){
                        low++;
                    }else if(nums[low]+nums[height]+nums[i]==0){
                        int prelow=nums[low];
                        int preheight=nums[height];
                        temp.push_back(nums[i]);
                        temp.push_back(prelow);
                        temp.push_back(preheight);
                        ans.push_back(temp);
                        temp.clear();
                        while(prelow==nums[low]&&low<height) low++;
                        //while(preheight==nums[height]) height--;
                    }
                }
            }
        }
        return ans;
    }
};
```
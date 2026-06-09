# 暴力法+剪枝？？四个for速度也不慢**
执行结果：
通过
显示详情
执行用时 :44 ms, 在所有 cpp 提交中击败了86.01% 的用户
内存消耗 :11.9 MB, 在所有 cpp 提交中击败了6.23%的用户
![QQ截图20191031234822.png](https://pic.leetcode-cn.com/c5658822ff7bf6c6ccf99aa4b6479c10e9e6c824cd94d7e7cf7c974011000b78-QQ%E6%88%AA%E5%9B%BE20191031234822.png)

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums1, int target) {
        vector<vector<int>> res;
        if(nums1.empty()||nums1.size()<4)
            return res;
        vector<int> nums = nums1;
        sort(nums.begin(),nums.end());
        //if(nums.front()>target||nums.back()<target)
        //    return res;
        int n = nums.size();
        vector<int> temp{0,0,0,0};
        for(int i=0; i<=nums.size()-4;i++){
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target){
                            break;
            }
            else if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target){
                            continue;
            }
            for(int j=i+1; j<=nums.size()-3;j++){
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target){
                            break;
                        }
                for(int k=j+1; k<=nums.size()-2;k++){
                    if(nums[i]+nums[j]+nums[k]+nums[k+1]>target){
                            break;
                        }
                    for(int h=k+1; h<=nums.size()-1;h++){
                        if(nums[i]+nums[j]+nums[k]+nums[h]==target){
                            temp[0] = nums[i];
                            temp[1] = nums[j];
                            temp[2] = nums[k];
                            temp[3] = nums[h];
                            if(!issame(res,temp))
                                res.push_back(temp);
                        }
                        if(nums[i]+nums[j]+nums[k]+nums[h]>target){
                            break;
                        }
                    }
                }
            }
        }
        return res;
            
          
        
        
    }
    bool issame(vector<vector<int>> res, vector <int> n){
        for(int i=0;i<res.size();i++){
            if(res[i][0]==n[0]&&res[i][1]==n[1]&&res[i][2]==n[2]&&res[i][3]==n[3])
                return true;
        }
        return false;
        
    }
};
```

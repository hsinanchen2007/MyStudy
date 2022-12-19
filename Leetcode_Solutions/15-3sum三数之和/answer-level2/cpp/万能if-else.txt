### 解题思路
此处撰写解题思路
大佬们都好强。
一个小时，勉强写出来。
思路很简单，实现过程中出现的问题过多。程序写的太少。
** 大致说下思路，问题切入点在于0：**
1.如果存在0，有两种可能，a.大于等于三个0，那么此时会有一组全0解；b.一个或两个0，此时如果有解，必是正负数各一个
2.不存在0，也只有两种可能, a.两个正数；b.两个负数
3.去重
去重是一个有点麻烦的地方，这里选用的是set物理强行去重。别的方法，各位大佬都有讲，不赘述了。
效率很低QAQ
**时间复杂度：o(n^2), 空间复杂度o(n)**
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> fin;
        vector<int> pos, neg, temp(3, 0);
        int zeroS=0, posf[1000000]={0}, negf[1000000] = {0};
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
                posf[nums[i]] = 1;
            }else if(nums[i]<0){
                neg.push_back(nums[i]);
                negf[-1*nums[i]] = 1;
            }else zeroS++;
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        
        if(zeroS>=1){
            if(zeroS>=3)fin.push_back(temp);
            for(int i=0;i<pos.size();i++){
                if(negf[pos[i]]){
                    temp[0] = -1*pos[i];
                    temp[1] = 0;
                    temp[2] = pos[i];
                    fin.push_back(temp);
                }
            }
        }
        for(int i=0;i<neg.size();i++){//两个负数
            for(int j=i+1;j<neg.size();j++){
                if(posf[-1*(neg[i]+neg[j])]){
                    temp[0] = neg[i];
                    temp[1] = neg[j];
                    temp[2] = -1*(neg[i]+neg[j]);
                    fin.push_back(temp);
                }
            }
        }
        for(int i=0;i<pos.size();i++){//两个正数
            for(int j=i+1;j<pos.size();j++){
                if(negf[pos[i]+pos[j]]){
                    temp[0] = pos[i];
                    temp[1] = pos[j];
                    temp[2] = -1*(pos[i]+pos[j]);
                    fin.push_back(temp);
                }
            }
        }
        
        //去重
        set<vector<int>> dr(fin.begin(), fin.end());
        fin.assign(dr.begin(), dr.end());
        return fin;
    }
};
```
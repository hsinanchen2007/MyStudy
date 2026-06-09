### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        bool visit[n]={false};
        int max1=0;
        for(int i=0;i<n;i++){
            if(visit[i]==true)continue;
            int num=0;
            int t=i;
            while(nums[t]!=i){
                visit[t]=true;
                num++;
                t=nums[t];
            }
            visit[t]=true;
            num++;
            max1=max(max1,num);
        }
        return max1;
    }
};
```
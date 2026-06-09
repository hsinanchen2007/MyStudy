### 解题思路
用了两个map，一个统计度，一个统计开始结束坐标

### 代码

```cpp
class Solution {
public:

    unordered_map<int,vector<int>> m;//统计开始和结束坐标
    unordered_map<int,int> m1;//统计度
    int findShortestSubArray(vector<int>& nums) {
        int max=0;//统计最大频数
        int min=50000;//统计最短长度
        //统计所有字符开始的坐标
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
            if(m1[nums[i]]>max) max=m1[nums[i]];
            if(m[nums[i]].size()==0){
                m[nums[i]].push_back(i);
            }
            else if(m[nums[i]].size()==1){
                m[nums[i]].push_back(i);
            }
            else if(m[nums[i]].size()==2){
                m[nums[i]][1]=i;
            }
        }
        unordered_map<int,int>::iterator it;
        for(it=m1.begin();it!=m1.end();it++){
            if(it->second!=max) continue;
            if(m[it->first].size()==2){
                if(m[it->first][1]-m[it->first][0]+1<min){
                min=m[it->first][1]-m[it->first][0]+1;
                }
            }
            else{
                return 1;
            }

        }
        return min;


    }
};
```
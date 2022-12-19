### 解题思路
一、使用结构体+vector向量来记录所有的值以及哪一组拥有这个值的情况
二、双指针法直接指就完事了

### 代码

```cpp
class Solution {
public:
    //第一版代码完成了正数的所有种情况，但是未考虑负数的情况
//    vector<int> smallestRange(vector<vector<int>>& nums) {
//        vector<int> all[100001];
//        int left=INT_MAX;
//        int right=INT_MIN;
//        int min1=INT_MAX;
//        for(int i=0;i<nums.size();++i)
//        {
//            for(int j=0;j<nums[i].size();++j)
//            {
//                all[nums[i][j]].push_back(i);
//                if(nums[i][j]<left)
//                left=nums[i][j];
//                if(nums[i][j]>right)
//                right=nums[i][j];
//            }
//        }
//        int i,j;int minl,minr;
//        for(i=left;i<=right;++i)
//        {
//            int r=i;set<int> vis;
//            for(j=r;j<=right;++j)
//            {
//                for(int k=0;k<all[j].size();++k)
//                {
//                    vis.insert(all[j][k]);
//                }
//                if(vis.size()==nums.size())
//                    break;
//            }
//            if(vis.size()==nums.size())
//            {
//                if(j-i+1<min1)
//                {
//                    minl=i;minr=j;
//                    min1=j-i+1;
//                }
//            }
//        }
//        vector<int> res;
//        res.push_back(minl);res.push_back(minr);
//        return res;
//    }
    //第二版代码，使用结构体来保存
    typedef struct a{
        int date;
        vector<int> temp;
    }aa;
    static  bool cmp(aa a,aa b)
    {
        return a.date<b.date;
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<aa> all;
        map<int,int> mp;
        int left=INT_MAX;
        int right=INT_MIN;
        int min1=INT_MAX;
        int count=0;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=0;j<nums[i].size();++j)
            {
                if(mp.find(nums[i][j])==mp.end())
                {
                    mp[nums[i][j]]=count;
                    aa temp;temp.date=nums[i][j];temp.temp.push_back(i);
                    all.push_back(temp);
                    count++;
                }
                else
                {
                    all[mp[nums[i][j]]].temp.push_back(i);
                }
            }
        }
        sort(all.begin(),all.end(),cmp);
        int i,j;int minl,minr;
        for(i=0;i<count;++i)
        {
            int r=i;set<int> vis;
            for(j=i;j<count;++j)
            {
                for(int k=0;k<all[j].temp.size();++k)
                {
                    vis.insert(all[j].temp[k]);
                }
                if(vis.size()==nums.size())
                    break;
            }
            if(vis.size()==nums.size())
            {
                int left1=all[i].date;int right1=all[j].date;
                if(right1-left1+1<min1)
                {
                    minl=left1;minr=right1;
                    min1=right1-left1+1;
                }
            }
        }
        vector<int> res;
        res.push_back(minl);res.push_back(minr);
        return res;
    }
};
```
### 解题思路
这两种方法都是对整个数组从头开始求和，然后每次确定边界，看边界中间有多少个数:
- 假设[i,j]是满足条件的一个区间那么有lower<=sum[i,j]<=upper，即lower<=sum(0,j]-sum(0,i)<=upper
- 也就是看j前面的和有多少在区间[sum(0,j]-upper,sum(0,j]-lower]中
方法很多，还可以用二分或二叉搜索树，我只写了暴力和树状数组的代码

### 代码
暴力
```
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long res=0,sum=0;
        set<long>s;
        map<long,int>mp;
        s.insert(0);
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            long l=sum-upper,r=sum-lower;
            for(auto it=s.lower_bound(l);it!=s.upper_bound(r);it++) res+=mp[*it];
            s.insert(sum);
            mp[sum]++;
        }
        return res;
    }
};
```
树状数组
```cpp
class Solution {
public:
    vector<int>tree;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long res=0,sum=0;
        vector<long>vec;
        vector<int>rank;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            vec.push_back(sum);
        }
        vector<long>temp=vec;
        torank(temp,rank);
        tree.resize(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            if(vec[i]<=upper&&vec[i]>=lower) res++;
            int l=lower_bound(temp.begin(),temp.end(),vec[i]-upper)-temp.begin();
            int r=upper_bound(temp.begin(),temp.end(),vec[i]-lower)-temp.begin();
            res+=getsum(r)-getsum(l);
            update(rank[i]);
        }
        return res;
    }
    void torank(vector<long>& nums,vector<int>& rank){//排序表
        vector<long>temp=nums;
        sort(nums.begin(),nums.end());
        map<long,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i+1;
        }
        for(int i=0;i<temp.size();i++){
            rank.push_back(mp[temp[i]]);
        }
    }
    int getsum(int pos){
        int sum=0;
        while(pos){
            sum+=tree[pos];
            pos-=lowbit(pos);
        }
        return sum;
    }
    void update(int pos){
        while(pos<tree.size()){
            tree[pos]+=1;
            pos+=lowbit(pos);
        }
    }
    int lowbit(int x){
        return x&(-x);
    }
};
```
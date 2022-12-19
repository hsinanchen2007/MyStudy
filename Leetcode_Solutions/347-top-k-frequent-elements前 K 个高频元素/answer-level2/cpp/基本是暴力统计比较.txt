```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>rec;
        for(int n:nums){
            rec[n]++;
        }
        vector<int>rec2;
        for(auto it=rec.begin();it!=rec.end();it++){
            rec2.push_back(it->second);
        }
        sort(rec2.begin(),rec2.end());
        int B=rec2[rec2.size()-k];
        vector<int>ans;
        for(auto it=rec.begin();it!=rec.end();it++){
            if(it->second>=B){ans.push_back(it->first);}
        }
        return ans;
    }
};
```
由于有sort,理论上是O(m log m),m=数组中不相同的元素的个数，一般m<n，如果相等的话都是1，看sort的实现原理。

转换成桶排序，反而多了4ms.
```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>rec;
        for(int n:nums){
            rec[n]++;
        }
        vector<int>rec2(nums.size(),0);
        for(auto it=rec.begin();it!=rec.end();it++){
            rec2[it->second-1]++;
        }
        int B=rec2.size();
        while((k>0)&&(B>0)){
            B--;
            if(rec2[B])k-=rec2[B];
        }
        vector<int>ans;
        for(auto it=rec.begin();it!=rec.end();it++){
            if(it->second>B){ans.push_back(it->first);}
        }
        return ans;
    }
};
```


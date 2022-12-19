```
//没有排序答案也是对的。。。
/*inline bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    if(a.first!=b.first)return a.first<b.first;
    return a.second<b.second;
}*/
const int maxn=1e4+100;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>ans;
        vector<int>res;
        for(int i=0;i<arr.size();i++){
            int count=0;
            int temp=arr[i];
            while(temp){
                if(temp&1)count++;
                temp=temp>>1;
            }
            pair<int,int>p(count,arr[i]);
            ans.push_back(p);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            res.push_back(ans[i].second);
        }
        return res;
        

    }
};
```

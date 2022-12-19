class Solution {
public:
    //滑动窗口加双指针
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int,vector<int>> mp;
        map<int ,int> count_for_each;
        vector<int> res;
        int n=nums.size(),length=99999999,start;
        bitset<3500> bs(0);
        for(int i=0;i<n;i++){
            count_for_each[i]=0;
            for(auto num:nums[i]){
                mp[num].push_back(i);
            }
        }
        map<int,vector<int>>:: iterator p=mp.begin(),q=mp.begin();
        while(q!=mp.end()){
            for(auto a:q->second){
                bs[a]=1;
                count_for_each[a]++;
            }
            while(bs.count()==n){
                if(q->first-p->first<length){
                    start=p->first;
                    length=q->first-p->first;
                }
                for(auto a:p->second){
                   if(--count_for_each[a]==0)bs[a]=0;
                }
                p++;
            }
            q++;
        }
        res.push_back(start);res.push_back(start+length);
        return res;
    }
};
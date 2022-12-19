class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>result;
        for(auto&n:words){
            result[n]++;
        }
        vector<pair<string,int>>res(result.begin(),result.end());
        auto cmp=[](const pair<string,int> &a,const pair<string,int> &b){
            if(a.second!=b.second)return a.second<b.second;
            else return a.first>b.first;
        };
        vector<string> re;
        make_heap(res.begin(),res.end(),cmp);
        for(int i=0;i<k;i++){
            string number;
            number=res.begin()->first;
            re.push_back(number);
            pop_heap(res.begin(),res.end(),cmp);
            res.pop_back();
        }
        return re;
    }
};
![QQ图片20191117153134.png](https://pic.leetcode-cn.com/d81789419e65aee766e5db20b5240651631914c7b9cd778fb66a98e9d3d5139a-QQ%E5%9B%BE%E7%89%8720191117153134.png)


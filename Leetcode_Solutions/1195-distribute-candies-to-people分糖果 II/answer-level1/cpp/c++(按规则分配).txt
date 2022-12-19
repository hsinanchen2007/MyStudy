```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> tmp,res(num_people,0);
        int used=0,i=0;
        while(used<candies) tmp.push_back(++i),used+=i;
        tmp[tmp.size()-1]-=used-candies;
        for(int i=0;i<tmp.size();i++) res[i%num_people]+=tmp[i];
        return res;
    }
};
```

```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
      set<int> ans(nums.begin(), nums.end());
      set<int>::iterator iter = ans.end();
      --iter;
      if(ans.size() >= 3){
          --iter;
          --iter;
          return *iter;
      }
      return *iter;
    }
};
```

```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums) mp[num]++;
        map<int,int>::iterator iter;
        iter = mp.begin();
        int count = 0;
        while(iter != mp.end()){
            count += 1;
            ++iter;
        }
        map<int,int>::reverse_iterator iter_reverse = mp.rbegin();   
        if(count < 3) return iter_reverse->first;
        ++iter_reverse;
        ++iter_reverse;
        return iter_reverse->first;
    }
};
```





```
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        set<int> res;
        for(int i=0;i<arr.size();i++){
            if(m.count(arr[i])) m[arr[i]]++;
            else m[arr[i]]=1;
        }
        map<int,int>::iterator iter;
        for(iter=m.begin();iter!=m.end();iter++){
            res.insert(iter->second);
        }
        if(res.size()==m.size()) return true;
        else return false;
    }
};
```

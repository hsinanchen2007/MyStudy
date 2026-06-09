multiset的红黑树来解
```
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> r;
        if(k==0) return r;
        multiset<int,greater<int>> m;
        for(auto i: arr){
            if(m.size()<k){
                m.insert(i);
            }else{
                multiset<int,greater<int>>::iterator z=m.begin();
                if(i<*z){
                    m.erase(z);
                    m.insert(i);
                }
            }
        }
        r.resize(k);
        copy_n(m.begin(),k,r.begin());
        return r;

    }
};
```

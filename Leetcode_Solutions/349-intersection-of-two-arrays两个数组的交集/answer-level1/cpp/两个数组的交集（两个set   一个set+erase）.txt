方法一
```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1,st2;
        vector<int> res;
        for(int n1:nums1) st1.insert(n1);
        for(int n2:nums2) st2.insert(n2);
        for(unordered_set<int>::iterator it = st1.begin();it!=st1.end();it++)
            if(st2.count(*it)) res.emplace_back(*it);
        return res;
    }
};
```
方法二
```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        vector<int> res;
        for(int n1:nums1) st.insert(n1);
        for(int n2:nums2){
            if(st.count(n2)){
                res.emplace_back(n2);
                st.erase(n2);
            } 
        } 
        return res;
    }
};
```


```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mymap;
        vector<int> res;

        for(auto num : nums1){
            mymap[num] ++;
        }
        for(auto num : nums2){
            if(mymap.count(num)){
                res.push_back(num);
                mymap[num] --;
                if(mymap[num]==0){
                    mymap.erase(num);
                }
            }
        }
        return res;
    }
};
```

* 执行用时 :16 ms, 在所有 C++ 提交中击败了47.21%的用户
* 内存消耗 :9.3 MB, 在所有 C++ 提交中击败了48.64%的用户

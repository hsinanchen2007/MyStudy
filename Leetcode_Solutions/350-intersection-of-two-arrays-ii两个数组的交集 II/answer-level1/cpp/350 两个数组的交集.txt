```
class Solution {
public:
    //注意因为有重复元素要统计，所以不能用unordered_set而是用unordered_multiset<int>;
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //首先将两个数组中较小的那一个插入到hash表中，

        if(nums1.size()>nums2.size()) return intersect(nums2,nums1);//将两个数组交换

        unordered_multiset<int> hash;
        for(auto x:nums1) hash.insert(x);

        vector<int >res;
        for(auto x:nums2)//遍历较大的数组
        {
            if(hash.count(x)>0)  
            {
                res.push_back(x);
            //这里删除要注意,不能直接删除这个数,因为这个数有好几个，直接删了就不对了
                auto it=hash.find(x);
                hash.erase(it);
            }
        }

        return res;
    }
};
```

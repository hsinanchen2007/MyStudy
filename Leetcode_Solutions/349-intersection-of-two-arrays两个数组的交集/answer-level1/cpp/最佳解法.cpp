本解法所用时仅次于使用C++内置的sort和set_intersection（使用STL基本可以肯定会是最快的，但面试等情况未必可用）。
优点：
1、使用无序集合而非一般集合或无序图，节约了时空
2、在检索无序集合时，将检索到的元素删去，而不是遍历answer数组，面对越大规模的问题，该方法效率越优。
```C++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> u;
        vector<int> answer;
        for(int i:nums1)
            u.insert(i);
        for(int i:nums2){
            auto a = u.find(i);
            if(a!=u.end()){
                answer.push_back(i);
                u.erase(a);
            }
        }
        return answer;
    }
};
```
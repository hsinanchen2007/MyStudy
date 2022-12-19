# 方法一：哈希
遍历数组一，将每个元素以及出现次数保存进：map<元素，出现次数>
```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        vector<int> res;
        for(int i=0; i<nums1.size(); i++){
            m[nums1[i]] += 1;
        }
        for(int k=0; k<nums2.size(); k++){
            if(m[nums2[k]]>0){
                res.push_back(nums2[k]);
                m[nums2[k]]--;
            }
        }
        return res;
    }
};
```
# 方法二：双指针
先对两个数组排序，设定两个值为0的指针，初始时分别指向两个数组第一个元素；
比较两个指针的元素是否相等。如果指针的元素相等，同时向前，并且将相等的元素放入结果数组；
如果指针的元素不相等，将元素较小的那个指针向前移；
循环知道一个数组终止。
```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i] > nums2[j]){
                j++;
            }else{
                i++;
            }
        }
        return res;
    }
};
```


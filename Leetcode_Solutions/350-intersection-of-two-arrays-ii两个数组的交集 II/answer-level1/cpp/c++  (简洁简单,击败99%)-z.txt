### 解题思路1
**使用map**
第一轮循环让map中的value值存储nums1中对应key值的元素数量，第二轮循环遍历num2中的元素，如果map中此时key为i对应的value大于等于1,即为交集元素，加入存储答案的vector中

### 代码

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    
        vector<int> res;
        unordered_map<int,int> ts;

        for(int i:nums1)
            ts[i]++;//使key为i的对应value值++,value值表示对应的key在ts这个map中有几个

         for(int i:nums2)       
            if(ts.find(i)!=ts.end() && --ts[i] >= 0)    //如果map中此时key为i对应的value大于等于1,即交集元素
            res.push_back(i);//加入到答案vector中

       return res;
    }
};
```
### 解题思路2
**排序+双指针**

### 代码

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,k=0;
        while( i < nums1.size() && k < nums2.size() )
        {
            if(nums1[i]==nums2[k])
            {
                res.push_back(nums1[i]);
                i++;
                k++;
            }
           else  if(nums1[i]>nums2[k])
                k++;
           else
                i++;
        }
       return res;
    }
};
```


### 先对nums1进行map无序编号保存，再去nums2中找到相同元素，找到就将频数归零。用s去保存每次相同的元素。
本人是个小菜菜，希望能碰到大佬指教。

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        int len1=nums1.size();
        int len2=nums2.size();
        vector<int> s;
        for(int i=0;i<len1;i++){
            m[nums1[i]]++;
        }
        for(int j=0;j<len2;j++){
            if(m[nums2[j]]>0){
                m[nums2[j]]=0;
                s.push_back(nums2[j]);
            }
        }
        return s;
    }
};
```
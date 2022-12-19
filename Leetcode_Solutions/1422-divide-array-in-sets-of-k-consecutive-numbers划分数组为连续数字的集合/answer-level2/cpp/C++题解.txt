![image.png](https://pic.leetcode-cn.com/6b7780a087fc7d8443263758325b731293a7b1640a649e9c16f7fa1ccd111192-image.png)

### 解题思路
最坏情况有$10^5$个数（包括重复）
一个数只删1次，假如一个数重复了m次那么最坏情况删m次。
算上排序，均摊时间复杂度 O($n log n$)

### 代码

```cpp
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> b,e;
        int n = nums.size();
        e = nums;
        sort(e.begin(),e.end());
        for(int i=0;i<n;i++) {
            if(!mp[e[i]]) {
                b.push_back(e[i]);
            }
            mp[e[i]]++;
        }
        for(int i=0;i<b.size();i++) {
            int a = b[i];
            if(mp[a]) {
                int f = mp[a];
                for(int j=0;j<k;j++) {
                    mp[a+j] -= f;
                    if(mp[a+j]<0) return false;
                }
            }
        }
        return true;
    }

};
```
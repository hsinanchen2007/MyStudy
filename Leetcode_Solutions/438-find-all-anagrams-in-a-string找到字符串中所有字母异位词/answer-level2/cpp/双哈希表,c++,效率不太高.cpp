### 解题思路
先把p字符串的每个元素和其数量存入unordered>map<char,int> mp2中
再使用双指针，来遍历s字符串并不断判断
![image.png](https://pic.leetcode-cn.com/3dde96a391875fea9002573cf074f981a7c347023d32875ecb9ddb5b7aadfaab-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int m = s.size(),n = p.size();
        if(s.size()<p.size()) return res;
        unordered_map<char,int> mp1,mp2;
        int left=0,right=0;
        while(right<n){
            char c2 = p[right];
            mp2[c2]++;
            right++;
        }//得到p的哈希表mp2
        right=0;
        while(right<m){
            char c1 = s[right];
            if(right<n-1){
                mp1[c1]++;
            }
            else{
                mp1[c1]++;
                if(mp1==mp2) res.push_back(left);
                mp1[s[left]]--;
                if(mp1[s[left]]==0) mp1.erase(s[left]);
                left++;
            }
            right++;
        }
        return res;

    }
};
```
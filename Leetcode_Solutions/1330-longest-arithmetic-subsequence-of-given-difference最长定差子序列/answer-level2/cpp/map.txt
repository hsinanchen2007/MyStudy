首先想到的是动态规划，因为和最长子序列类似，但是会超时

之后换思路，只要将出现过的元素用字典记录下来，其键对应的值表示包含其键所能构成的最长序列。

```
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>m;
        int len=0;
        for(auto i:arr){
            m[i]=m[i-difference]+1;
            len=max(m[i],len);
        }
        return len;
    }
};
```

个人网站:[liyiping](https://liyiping.cn)

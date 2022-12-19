这个一开始是题目不太好理解，
其实简单的来说，就是把输入参数列表中每两个组成一对，记为（a,b）;
则往输出列表添加a个b，遍历一次列表即可
```
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        int a;int b;vector<int> ans;
        for(int i = 0,j;i < n;i += 2){
            a = nums[i];b = nums[i+1];
            for(j = 0;j < a;++j)
                ans.push_back(b);
        }return ans;
    }
};
```

![捕获2.JPG](https://pic.leetcode-cn.com/773a08602e5d2e7448b2bb3c598670be5049db346ea278af419e01849311354c-%E6%8D%95%E8%8E%B72.JPG)


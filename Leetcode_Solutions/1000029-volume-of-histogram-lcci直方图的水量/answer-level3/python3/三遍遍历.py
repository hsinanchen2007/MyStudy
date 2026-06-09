### 解题思路
此处撰写解题思路此处撰写解题思路此处撰写解题思路此处撰写解题思路此处撰写解题思路此处撰写解题思路此处撰写解题思路此处撰写解题思路此处撰写解题思路此处撰写解题思路此处撰写解题思路此处撰写解题思路此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        vector<int> leftmax(n,height[0]);
        vector<int> rightmax(n,height[n-1]);
        for(int i =1;i<n;i++) leftmax[i] = max(leftmax[i-1],height[i]);
        for(int i =n-2;i>=0;i--) rightmax[i] = max(rightmax[i+1],height[i]);
        int ans=0;
        for(int i =0;i<n;i++) ans+=min(leftmax[i],rightmax[i])-height[i];
        return ans;

    }
};
```
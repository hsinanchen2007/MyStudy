### 解题思路
这是我做的第一道有关双指针的题。
我觉得双指针的关键包括以下内容：
1. 双指针的初始位置
2. 指针的更新条件

这道题里我一直纠结一点，就是更新到两个边的高度相同到了该更新哪个指针呢？后来想一想，如果两边都相同，那么最大值对应的两边一定不单独包括这两边的某一边，所以此时不管更新哪个指针都是一样的。


### 代码

```简洁写法 []
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans(0);
        for(int i=0,j=height.size()-1;i<j;){
            ans = max(ans, (j-i)*min(height[i],height[j]));
            min(height[i],height[j])==height[i]?i++:j--;
        }
        return ans;
    }
};
```
```我的原始写法 []
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans(0);
        int curArea;
        for(int i=0,j=height.size()-1;i<j;){
            curArea = (j-i)*min(height[i],height[j]);
            ans = max(ans,curArea);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};
```


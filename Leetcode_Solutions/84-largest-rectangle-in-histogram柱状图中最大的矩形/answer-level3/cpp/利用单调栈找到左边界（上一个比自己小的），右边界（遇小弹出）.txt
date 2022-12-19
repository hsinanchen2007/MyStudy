### 解题思路
注意这一行
ans=max(heights[temp]*(i-mono.top()-1),ans);//注意这里
之前写成了
ans=max(heights[temp]*(i-temp-1),ans);
### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> mono;
        mono.push(-1);
        int ans=0;
        int temp=0;
        for(int i=0;i<heights.size();i++){
            while(mono.top()!=-1&&heights[mono.top()]>=heights[i]){
            temp=mono.top();
            mono.pop();
            ans=max(heights[temp]*(i-mono.top()-1),ans);//注意这里
            }
            mono.push(i);
        }
        int s;
        while(mono.top()!=-1){
            temp=mono.top();
            mono.pop();
            s=heights.size();
            ans=max(heights[temp]*(s-mono.top()-1),ans);
        }
        return ans;
    }
};
```
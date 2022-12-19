```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> pos; // MaxStack
        int mx=0, i=0;
        for(heights.push_back(0); i<heights.size(); pos.push(i++)){
            while(pos.size() && heights[pos.top()]>heights[i]){
                int h=heights[pos.top()];
                pos.pop();
                mx=max(mx,pos.size()?(i-pos.top()-1)*h:i*h);
            }
        }
        return mx;
    }
};
```

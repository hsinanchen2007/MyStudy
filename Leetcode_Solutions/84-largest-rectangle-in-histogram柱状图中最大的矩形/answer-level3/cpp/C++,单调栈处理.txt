```
class Solution {
public:
//单调栈求解
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;//注意栈中存放的是数组heights的下标
        int ans=0,cur;
        //heights.push_back(0);
        //st.push(-1);
        int n=heights.size();
        for(int i=0;i<=n;i++){//注意这里是i<=n有等于号，因为为了处理边界情况,eg:[1]
            if(i<n)cur=heights[i];else cur=-1;//下面这一个也是为了防止heights[n]进行的处理
            while(!st.empty()&&cur<=heights[st.top()]){
                int val=st.top();
                st.pop();
                int h=heights[val];
                int w=st.empty()?i:i-st.top()-1;
                ans=max(ans,h*w);
            }
            st.push(i);
        }
        return ans;
    }
};
```

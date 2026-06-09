维护一个单独递增的栈，去求l数组和r数组，l数组的l[i]表示向左的第一个比heights[i]小的heights数组下标，r数组的r[i]表示向右的第一个比heights[i]小的heights数组下标，这样就能遍历一遍得到以当前i的高度的最大矩阵面积为**(r[i]-l[i]+1)\*heights[i]**，这里的r[i]和l[i]分别进行了-1和+1的操作，正常按照l和r数组的定义面积应该为**(r[i]-l[i]-1)\*heights[i]**，而维护单调栈就是为了求L和R数组，原理很简单，当前的heights[i]值小于等于栈顶的值就pop()，直到当前的heights[i]值大于栈顶，此时的栈顶元素下标就是L或者R数组的值。
代码如下：
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size(),top;
        vector <int> l(len,0),r(len,0);
        stack <int> sta;
        for(int i=0;i<len;i++){   //求L数组
            while(!sta.empty()&&heights[i]<=heights[sta.top()]) sta.pop();
            if(sta.empty()) l[i]=0;
            else l[i] = sta.top()+1;
            sta.push(i);
        }
        while(!sta.empty()) sta.pop();

        for(int i=len-1;i>=0;i--){ //求R数组
            while(!sta.empty()&&heights[i]<=heights[sta.top()]) sta.pop();
            if(sta.empty()) r[i]=len-1;
            else r[i] = sta.top()-1;
            sta.push(i);
        }
        int ans=0;
        for(int i=0;i<len;i++){    //找到最大值
            ans = max(ans,(r[i]-l[i]+1)*heights[i]);
            //cout<<l[i]<<" "<<r[i]<<endl;
        }
        return ans;
    }
};
```

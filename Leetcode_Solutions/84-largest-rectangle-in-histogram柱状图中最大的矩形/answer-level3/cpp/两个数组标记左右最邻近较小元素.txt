```
const int N=30000;
int l[N],r[N];//标记数组，标记左右最邻近较小元素的下标
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0){
            return 0;
        }
        int n=heights.size();
        l[0]=-1;//左边比0号元素小的为-1号元素
        for(int i=1;i<n;i++){
            int j=i-1;
            while(j>=0&&heights[i]<=heights[j]){//如果j号元素大于等于i号元素
                j=l[j];//找到左边比j号小的第一个元素
            }
            l[i]=j;
        }
        r[n-1]=n;//右边比n-1号元素小的为n号元素
        for(int i=n-2;i>=0;i--){//右边同理
            int j=i+1;
            while(j<n&&heights[i]<=heights[j]){
                j=r[j];
            }
            r[i]=j;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(r[i]-l[i]-1));//面积公式
        }
        return ans;
    }
};
```
16 ms	7.8 MB	Cpp
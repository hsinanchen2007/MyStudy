&emsp;&emsp;先按起点排序区间，然后设初始位置cur=0，之后找在**起点在cur之前**的所有区间的最远的终点，然后将该终点设置为cur，直到cur大于等于T返回答案或者最远终点没超过cur时返回-1。
```c++
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        int cur = 0, ans = 0, nxt = 0;
        for(int i = 0; i < clips.size() && nxt < T; ++i){
            if(clips[i][0] <= cur) nxt = max(nxt, clips[i][1]);
            else if(clips[i][0] > nxt) return -1;
            else{ ans++; cur = nxt; nxt = clips[i][1]; }
        }
        if(nxt >= T) return ans+1;
        return -1;
    }
};
```

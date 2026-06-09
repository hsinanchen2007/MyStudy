

### 代码

```cpp
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int time[clips.size()];
        memset(time,0,sizeof(time));
        int max_i=0;
        int max=0;
        for(int i=0;i<clips.size();i++){
            if(clips[i][1]<=T) time[i]=clips[i][1]-clips[i][0];
            if(clips[i][0]>=T) time[i]=0;
            if(clips[i][0]<=T&&clips[i][1]>=T) time[i]=T-clips[i][0];
            if(time[i]>max){
                max=time[i];
                max_i=i;
            }
        }
        int count=1;
        int left=clips[max_i][0];
        int right=clips[max_i][1];
        while(left>0){
            int left_min=left;
            for(int i=0;i<clips.size();i++){
                if(clips[i][0]<=left_min&&clips[i][1]>=left) left_min=clips[i][0];
            }
            if(left_min==left) return -1;
            else{
                count++;
                left=left_min;
            }
        }
        while(right<T){
            int right_max=right;
            for(int i=0;i<clips.size();i++){
                if(clips[i][0]<=right&&clips[i][1]>=right_max) right_max=clips[i][1];
            }
            if(right_max==right) return -1;
            else{
                count++;
                right=right_max;
            }
        }
        return count;
    }
};
```
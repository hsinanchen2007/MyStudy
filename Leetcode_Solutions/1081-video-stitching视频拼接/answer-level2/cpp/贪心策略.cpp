```
class Solution {
public:
    int len,start,end,rec,res=1;
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end(),cmp);
        len = clips.size();
        for(int i=0;i<len;i++) if(clips[i][0]==0) start = i; //找到第一个以0开头结尾最大的起点
        if(clips[start][0]!=0||clips[len-1][1]<T) return -1;//最小最大范围判断
        end = clips[start][1];
        for(int i=start+1;i<len;i++) {
            if(end>=T) break;//如果结尾已达到最大值不需要多的片段了
            rec = -1;
            for(int j=i;j<len;j++) if(clips[j][0]<=end) rec = j;//查找与当前片段可以相接的结尾最长的片段
            if(rec==-1) return -1;//没有找到即产生断层
            end = clips[rec][1];
            res++;
            i = rec;
        }
        return res;
    }
    static bool cmp(const vector<int>&a,const vector<int>&b) { //按结尾较大的排后面的原则排序
        if(a[1]!=b[1]) return a[1] < b[1];
        else return a[0] < b[0];
    }
};
```

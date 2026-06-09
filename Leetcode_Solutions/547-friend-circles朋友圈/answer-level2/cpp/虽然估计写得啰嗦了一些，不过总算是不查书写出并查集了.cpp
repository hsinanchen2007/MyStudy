最后的计算不重复元素个数用了先排序再计数跳跃，应可改进。
```
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> rec;
        for(int i=0;i<M.size();i++){
            rec.push_back(i);}
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                if((M[i][j])&&(rec[i]!=rec[j])){
                    int tp1=i,tp2=j;
                    while(rec[tp1]!=rec[rec[tp1]]){tp1=rec[tp1];}
                    while(rec[tp2]!=rec[rec[tp2]]){tp2=rec[tp2];}
                    int t=min(rec[tp1],rec[tp2]);
                    tp1=i;tp2=rec[i];
                    while(tp1!=tp2){
                        rec[tp1]=t;
                        tp1=tp2;
                        tp2=rec[tp2];}
                    rec[tp2]=t;
                    tp1=j;tp2=rec[j];
                    while(tp1!=tp2){
                        rec[tp1]=t;
                        tp1=tp2;
                        tp2=rec[tp2];}
                    rec[tp1]=t;}
        }}
        for(int i=rec.size()-1;i>0;i--){
            int tp1=i,tp2,t;
            while(rec[tp1]!=rec[rec[tp1]]){tp1=rec[tp1];}
            t=rec[tp1];tp1=i;tp2=rec[i];
            while(tp1!=tp2){
                rec[tp1]=t;
                tp1=tp2;
                tp2=rec[tp2];}
        }
        sort(rec.begin(),rec.end());
        int s=1;
        for(int i=1;i<rec.size();i++){
            if(rec[i]>rec[i-1]){s++;}
        }
        return s;
    }
};
```
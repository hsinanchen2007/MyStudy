```
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;//短板效应
        if(arr.size()<=0) return ans;
        int i,j;
        vector<int> cmax(arr.size());
        cmax[0]=arr[0];
        for(i=1;i<arr.size();i++){
            cmax[i]=max(arr[i],cmax[i-1]);
        }
        int tmax=cmax[0];
        for(i=0;i<cmax.size();i++){
            if(tmax<cmax[i]) tmax=cmax[i];
            if(tmax==i){
                ans++;
                if(i+1<cmax.size()) tmax=cmax[i+1];
            }
        }
        return ans;
    }
};
```

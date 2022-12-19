```
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int left[N+1]={0};
        int right[N+1]={0};
        for(int i=0;i<trust.size();i++){
            left[trust[i][0]]++;
            right[trust[i][1]]++;
        }
        for(int i=1;i<N+1;i++){
            if(right[i]==(N-1)&&left[i]==0)
                return i;
            
        }
        return -1;
    }
};
```

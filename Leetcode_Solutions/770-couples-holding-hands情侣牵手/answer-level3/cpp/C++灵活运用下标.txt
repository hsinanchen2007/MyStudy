```cpp
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size(),N=0;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            a[row[i]]=i;
        for(int i=0;i<n;i+=2){
            int p=row[i]+1;
            if(row[i]%2)
                p=row[i]-1;
            while(row[i+1]!=p){
                int t=row[i+1];
                row[i+1]=row[a[p]];
                row[a[p]]=t;
                a[row[a[p]]]=a[p];
                N++;
            }
        }
        return N;
    }
};
```

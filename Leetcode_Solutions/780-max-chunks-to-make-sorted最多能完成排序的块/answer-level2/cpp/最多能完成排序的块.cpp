```
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size()==0) return 0;
        
        int e=0;
        int i=0;
        int ans = 0;
        while(i<arr.size()){
            while(i<=e){
                e = max(e, arr[i]);
                i++;
            }
            e = i;
            ans += 1;
        }
        return ans;
    }
```
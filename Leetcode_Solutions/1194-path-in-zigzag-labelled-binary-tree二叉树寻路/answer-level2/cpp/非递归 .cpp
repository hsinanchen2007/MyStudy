```
        vector<int> res;
        while(label!=1){
            res.push_back(label);
            label = label/2;
        }
        res.push_back(1);
        reverse(res.begin(),res.end());

        int total = 5;
        int jiou = res.size()%2;
        for(int i=1;i<=res.size();i++){
            if(i>=3) total = 2*total + 1;
   
            if( i%2!=jiou && i>=2){
                res[i-1] = total - res[i-1];
            }
        }
        return res;
```

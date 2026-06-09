```
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        int Min=min(x,y);
        if(Min==1) Min=2; //底不能为1
        int n=log(bound)/log(Min) +1;
        vector<int> vec;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                int num=pow(x,i)+pow(y,j);
                if(num<=bound) vec.push_back(num);
            }
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()), vec.end());
        return vec;
    }
```

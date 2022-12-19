1. 首先赋值使 x<y<z   
2.  正常情况下{2,y-x-1+z-y-1}
3. 对间隔为1和间隔为2的情况分别讨论

如果间隔都为1   {0,0}

如果间隔都为2   {1,2}

如果只有一个间隔为1 或  只有一个间隔为2 答案为{1,y-x-1+z-y-1}

```
    vector<int> numMovesStones(int a, int b, int c) {
        int x=min(min(a,b),c);
        int z=max(max(a,b),c);
        int y=a+b+c-x-z;
        
        if(y-x==1 && z-y==1)
            return {0,0};
        if(y-x==2 && z-y==2)
            return {1,2};
        else{
            int maxn=y-x-1+z-y-1;
            if(y-x==1 || z-y==1 || y-x==2 || z-y==2){
                return {1,maxn};
            }
            else{
                return {2,maxn};
            }
        }
        return {};
    }
```

    
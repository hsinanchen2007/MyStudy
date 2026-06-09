虽然时间复杂度很高，就记录一下这个用resize的二维数组的初始化把
```
        vector<vector<int>> res;      //声明二维数组
        res.resize(r);                //行数为r
        for(int i=0;i<r;i++)
            res[i].resize(l);         //列数为l
```

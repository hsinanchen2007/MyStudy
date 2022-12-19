![image.png](https://pic.leetcode-cn.com/1458b00daa6335fc8ab13ba9ce5151528186b2bdc2f47bae04e64e6ad285feb6-image.png)
解题思路：每行收尾插入1，中间插入左上加右上，相对简单且容易理解。
```
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if(numRows==0) return res;
        res[0].push_back(1);//numRows=1时
        for(int i=1;i<numRows;i++){
            res[i].push_back(1);
            for(int j=1;j<i;j++) res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            res[i].push_back(1);
        } 
        return res;
    }
```

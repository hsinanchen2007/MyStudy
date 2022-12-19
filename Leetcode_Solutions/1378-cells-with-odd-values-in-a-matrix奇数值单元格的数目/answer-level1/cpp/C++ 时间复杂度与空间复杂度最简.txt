已知奇偶互斥，可以抽象为0和1符号（即用bool变量）（降低占用空间）
奇+偶=奇  偶+奇=奇 只需统计各行各列的奇偶数即可，随后使用公式即可算出（时间复杂度最简）
**时间复杂度：O（indices.length）
空间复杂度：O（m+n）**
```
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        //一.创建两个数组，存储各行各列的奇偶性,奇为true，偶为false，初始化为均为false
        vector<bool> rows(n,false);
        vector<bool> cols(m,false);

        //二.遍历indices，更新rows和cols，并对各个奇数个数统计
        int a=0,b=0;//a为rows的奇数个数，b为cols的奇数个数
        for(int i=0;i<indices.size();++i){
            int x=indices[i][0];int y=indices[i][1];//x，y分别存储对哪一行哪一列进行操作
            if(rows[x]){rows[x]=false;--a;}
            else{rows[x]=true;++a;}
            if(cols[y]){cols[y]=false;--b;}
            else{cols[y]=true;++b;}
        }

        //三.返回结果，由自己总结的公式：sum=a*(m-b)+b*(n-a)直接得出奇数个数
        return a*(m-b)+b*(n-a);
    }
};
```


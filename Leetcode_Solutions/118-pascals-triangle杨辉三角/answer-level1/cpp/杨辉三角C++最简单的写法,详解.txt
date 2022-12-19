执行用时 :4 ms, 在所有 C++ 提交中击败了94.42%的用户

开始分析前，先别急，先来看一下当前的代码，然后下面我们再逐行分析
```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec(numRows);   
        int i,j;                           
        if(numRows<=0)
            return vec;
        for(i=0;i<numRows;i++)
            for(j=0;j<=i;j++)
                if(j==0||j==i)
                    vec[i].push_back(1);
                else
                    vec[i].push_back(vec[i-1][j-1]+vec[i-1][j]);
        return vec;
    }
};
```
首先我们要来分析一下这些代码，我们定义了一个二维向量(数组)(numRows*numorRows)
```
vector<vector<int>> vec(numRows);
```
下面的i和j我们可以理解为行和列
```
int i,j;
```
执行前我们需要来执行以下判断，如果我传入的是0或者-1之类的，那么我们可以直接返回对象
```
if(numRows<=0)
    return vec;
```
```
for(i=0;i<numRows;i++)     //访问行
    for(j=0;j<=i;j++)       //访问列
        if(j==0||j==i)      //如果当前列=行首或者行尾
            vec[i].push_back(1);    //插入1
        else
            vec[i].push_back(vec[i-1][j-1]+vec[i-1][j]);    //插入当前位置的(上一行和上一列加上上一行的当前列)
return vec;                 //返回对象
```
看到这里相信你已经理解了
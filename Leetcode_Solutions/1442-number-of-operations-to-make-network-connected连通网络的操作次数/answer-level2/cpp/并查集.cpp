### 解题思路
并查集模板题，注释在代码中

### 代码

```cpp
class Solution {
public:
    int find(vector<int>&father,int x){//查找根节点
        while(x!=father[x])x=father[x];
        return x;
    }
    int makeConnected(int n, vector<vector<int>>& conn) {
        vector<int>father(n); 
        vector<bool>isfather(n);
        int len = conn.size(),cicle=0;
        if(len<n-1)return -1;//如果线不够连返回-1
        for(int i=0;i<n;i++)father[i]=i;//初始化，将所有机器都当作根节点
        for(int i=0;i<len;i++){
            int xf = find(father,conn[i][0]);
            int yf = find(father,conn[i][1]);
            if(xf!=yf){//把同一个圈子的所有机器连在一起
                father[yf]=xf;
            }
        }
        for(int i=0;i<n;i++){
            if(i==find(father,i))isfather[i]=1;
            if(isfather[i])cicle++;//记录根节点数目
        }   
        return cicle-1;//返回圈子连线数
    }
};
```
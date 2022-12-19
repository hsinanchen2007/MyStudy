### 解题思路
思路就是模拟一圈一圈的读写，引入层的概念，将便于代码书写。具体也就是左到右，上到下，右到左，下到上的移动，将边界-层作为新的边界。具体看代码和注释。
时间 12ms，78.1%；
内存 11.2MB,100%;
这种题写个初步的把数字一打印就很快能调好了，直接想很容易不全面。难度我认为是mid的。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> res;
        int n=matrix.size();
        if(n==0) return res;
        int m=matrix[0].size();
        if(m==0) return res;
        int i=0;
        int j=0;
        int chen=1;
        while(chen<=min(n,m)/2){
        for(;j<m-chen;j++){         //注意不会把这行或列走完，因为会结尾加一，所以下一动作就走掉了。
            res.push_back(matrix[i][j]);  
        }
        for(;i<n-chen;i++){
            res.push_back(matrix[i][j]);
        }
        for(;j>=chen;j--){
            res.push_back(matrix[i][j]);
        }
        for(;i>=chen;i--){                    //最后把整列走完了，便于后面的特殊情况
            res.push_back(matrix[i][j]);
        }
        i++;       //因为最后走位了，所以要做一点调整，二者直接等于层也可以；
        j++;
        chen++;
        }
        if(res.size()==n*m) return res; //正好就不用管了
        if(n>m){      //n大说明有一列每走完，最后就不用管层数了；
            for(;i<=n-chen;i++) res.push_back(matrix[i][j]);
        }
        else{       //反之有一行没走完；
            for(;j<=m-chen;j++) res.push_back(matrix[i][j]);
        }
       // for(auto p:res) cout<<p<<" ";
        return res;
    }
};
```
### 解题思路
enum direction {right, down, left, up} dir;
通过右、下、左、上来控制下一个数放在矩阵中的位置。
核心代码如下：
```
        dir = right;
        int temp = 1;
        int i=0, j=0;
        result[0][0] = 1;
        while(temp != n*n){
            switch(dir){
                case right:
                    while(j+1<n&&result[i][j+1]==0){
                        result[i][++j] = ++temp;
                        cout<<result[i][j-1]<<endl;
                    }
                    dir = down;
                    break;
                case down:
                    while(i+1<n&&result[i+1][j]==0){
                        result[++i][j] = ++temp;
                        cout<<result[i-1][j]<<endl;
                    }
                    dir = left;
                    break;
                case left:
                    while(j-1>=0&&result[i][j-1]==0){
                        result[i][--j] = ++temp;
                        cout<<result[i][j+1]<<endl;
                    }
                    dir = up;
                    break;                    
                case up:
                    while(i-1>=0&&result[i-1][j]==0){
                        result[--i][j] = ++temp;
                        cout<<result[i+1][j]<<endl;
                    }
                    dir = right;
                    break;               
            }
        }
```


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        enum direction {right, down, left, up} dir;
        vector<vector<int>> result(n, vector<int>(n, 0));
        for(int l=0;l<n;l++){
            for(int k=0;k<n;k++){
                cout<<result[l][k]<<'\t';
            }
            cout<<endl;
        }
        dir = right;
        int temp = 1;
        int i=0, j=0;
        result[0][0] = 1;
        while(temp != n*n){
            switch(dir){
                case right:
                    while(j+1<n&&result[i][j+1]==0){
                        result[i][++j] = ++temp;
                        cout<<result[i][j-1]<<endl;
                    }
                    dir = down;
                    break;
                case down:
                    while(i+1<n&&result[i+1][j]==0){
                        result[++i][j] = ++temp;
                        cout<<result[i-1][j]<<endl;
                    }
                    dir = left;
                    break;
                case left:
                    while(j-1>=0&&result[i][j-1]==0){
                        result[i][--j] = ++temp;
                        cout<<result[i][j+1]<<endl;
                    }
                    dir = up;
                    break;                    
                case up:
                    while(i-1>=0&&result[i-1][j]==0){
                        result[--i][j] = ++temp;
                        cout<<result[i+1][j]<<endl;
                    }
                    dir = right;
                    break;               
            }
        }
        return result;
        
    }
};
```
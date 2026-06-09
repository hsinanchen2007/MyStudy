### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l=matrix.size();
        int tmp0,tmp1,tmp2,i=0,p=4;
        int x,y;
        while(i<(l+1)/2){
            for(int a=i;a<l-1-i;++a){
                p=4;
                x=i;y=a;
                while(p-->0){
                    if(p==3){
                        tmp1=matrix[y][l-1-x];
                        matrix[y][l-1-x]=matrix[x][y];
                    }
                    else{
                        tmp2=matrix[y][l-1-x];
                        matrix[y][l-1-x]=tmp1;
                        tmp1=tmp2;
                    }
                    tmp0=x;
                    x=y;
                    y=l-1-tmp0;
                }
            }
            i++;
        }
        return;
    }
};
```
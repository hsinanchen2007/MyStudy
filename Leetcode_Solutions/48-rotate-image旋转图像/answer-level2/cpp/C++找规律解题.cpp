假设当前的数据为matrix[i][j],矩阵的维度为[0,len-1][0,len-1],则经过观察，经过变换后有以下的规律:
matrix[i][j]取代matrix[j][len-1-i]
matrix[j][len-1-i]取代matrix[len-1-i][len-1-j]
matrix[len-1-i][len-1-j]取代matrix[len-1-j,i]
matrix[len-1-j,i]取代matrix[i][j]
这样就可以缩小数组的遍历，每回一次性修改这四个值。不过，当len为奇数或偶数的时候，又有一些区别。具体地，见下面的代码：
```
void rotate(vector<vector<int>>& matrix) {
        int len=matrix.size();
        if(len<=1)
            return;
        int len2=matrix[0].size();
        if(len!=len2)
            return;
        int c=(len+1)/2,d=0;
        if(len%2==0)
            d=c;
        else
            d=c-1;
        int tmp1,tmp2,tmp3;
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<d;j++)
            {
                tmp1=matrix[j][len-1-i];
                tmp2=matrix[len-1-i][len-1-j];
                tmp3=matrix[len-1-j][i];
                matrix[j][len-1-i]=matrix[i][j];
                matrix[len-1-i][len-1-j]=tmp1;
                matrix[len-1-j][i]=tmp2;
                matrix[i][j]=tmp3;
            }      
        }
        return;        
    }
```

```
vector<int> spiralOrder(vector<vector<int>>& matrix) {	
		int m=matrix.size();
        vector<int> res;
        if(m==0){
            return res;
        }
        int n=matrix[0].size();
        
        //  (min(m,n)+1)/2
        for(int i=0;i<(min(m,n)+1)/2;i++){
            int x=i,y=i;
            for(;y<n-i;y++){
                res.push_back(matrix[x][y]);
            }
            y--;
            
            if((m & 1) && x==(m>>1)){
                break;
            }
            for(x=x+1;x<m-i;x++){
                res.push_back(matrix[x][y]);
            }
            x--;
            
            if((n & 1) && y==(n>>1)){
                break;
            }
            for(y=y-1;y>=i;y--){
                res.push_back(matrix[x][y]);
            }
            y++;
            
            for(x=x-1;x>i;x--){
                res.push_back(matrix[x][y]);
            }
        }
        return res;
	}
```

考虑 m*n 的矩阵, 首先需要计算最外层循环次数. (min(m,n)+1)/2 : 起点(i,i); i从0开始。

然后通过四个循环进行遍历，注意边界条件。  注意使用for循环的时候，最后的数据x，y是超出边界的，需要将x，y复原一次。   判断循环结束的条件：向下循环或者向左循环的时候发现没有元素！！！（理解这一点很关键）    

实际情况请自行模拟。

![image.png](https://pic.leetcode-cn.com/85a14cde9d86a3d68f84906f71cc1cc189bc221cade2761123637ac0eca93008-image.png)

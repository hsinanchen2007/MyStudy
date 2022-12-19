题目较为简单，主要为了提升效率，使用了两边一起检测的方法。


    bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
        if(matrixSize==0 || matrixColSize==0)   return false;
        int row=0, col = *matrixColSize-1;
        
        while(row<matrixSize && col>=0){
            if(matrix[row][col]<target)
                row++;
            else if(matrix[row][col]>target)
                col--;
            else
                return true;
        }
        return false;
    }

![TIM图片20191128103157.png](https://pic.leetcode-cn.com/8c400682f826ae58b7642a91b3a191d855554e2a9c97235da4805397ec0ab580-TIM%E5%9B%BE%E7%89%8720191128103157.png)

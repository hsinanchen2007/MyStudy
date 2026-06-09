

void rotate(int** matrix, int matrixSize,int* matrixColSize){
//一个N*N二维矩阵可以划分为N/2圈，每一圈是一个正方形，要旋转矩阵只需按照顺时针方向覆盖每一圈
//的相邻边对应元素
    int i,upc,leftr,downc,rightr,temp;
    for(i=0;i<matrixSize/2;i++){//从第0圈开始遍历
        upc=i;//“上”方边元素列下标，初始为其首元素列下标
        leftr=i;//"左"方边元素行下标，初始为其首元素行下标
        downc=matrixSize-1-i;//"下"方边元素列下标，初始为为其尾元素列下标
        rightr=matrixSize-1-i;//"右"方边元素行下标，初始为为其尾元素行下标
        while(upc<matrixSize-1-i){
            temp=matrix[leftr][matrixSize-1-i];//保存“左”的原值
            matrix[leftr][matrixSize-1-i]=matrix[i][upc];//“上”覆盖“左”

            temp=temp^matrix[matrixSize-1-i][downc];//“左”覆盖下，并保存“下”的原值
            matrix[matrixSize-1-i][downc]=temp^matrix[matrixSize-1-i][downc];
            temp=temp^matrix[matrixSize-1-i][downc];

            temp=temp^matrix[rightr][i];//"下"覆盖右，并保存“右”的原值
            matrix[rightr][i]=temp^matrix[rightr][i];
            temp=temp^matrix[rightr][i];

            matrix[i][upc]=temp;//"右"覆盖“上”

            upc++;leftr++;downc--;rightr--;//更新各边下标
        }
    }
}
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int f1,f2;
    f1=f2=0;
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<*matrixColSize; j++){
            if(matrix[i][j]==0){
                if(i==0){
                    f1=1;
                }
                if(j==0){
                    f2=1;
                }
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }

    for(int i=1; i<matrixSize; i++){
        if(matrix[i][0]==0){
            for(int k=0; k<*matrixColSize; k++){
                matrix[i][k]=0;
            }
        }
    }

    for(int i=1; i<*matrixColSize; i++){
        if(matrix[0][i]==0){
            for(int k=0; k<matrixSize; k++){
                matrix[k][i]=0;
            }
        }
    }

    if(f1){
        for(int i=0; i<*matrixColSize; i++){
            matrix[0][i]=0;
        }
    }

    if(f2){
        for(int i=0; i<matrixSize; i++){
            matrix[i][0]=0;
        }
    }

}
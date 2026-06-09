### 解题思路
此处撰写解题思路
1. 利用线性代数的旋转函数：x' = x cos - y sin; y' = x sing + y cos，求取旋转后的坐标;
2. 图片坐标系和笛卡尔坐标系在y轴方向是反向的，所以顺时针旋转，在笛卡尔坐标系里是逆时针旋转，旋转角度为90度；
3. 在矩阵大小为奇数和偶数时，中心点不同，所以在计算旋转后的坐标时，需要乘以2，来消除奇偶的影响；
4. 由于是原地顺时针旋转，在遍历的时候选择逆时针遍历3/4圈即可；
5. 需要由外向里一个圈一个圈遍历；
### 代码

```c
/* *************************************************  **
** 1. first  : found the rotation function
** 2. second : iter the table in diffrent rotation size.
** *************************************************  */

typedef struct _point_t {
    int x;
    int y;
}point_t;

int Rotate90(const point_t *input, point_t *output, int n, int DEBUG){
    point_t center = {n-1, (n-1)};
    point_t src = {input->x *2, input->y * 2};
    point_t zero = {src.x - center.x, src.y - center.y};

    // 由于图片的旋转方向和笛卡尔坐标的旋转方向相反，所以此处逆时针旋转，就是原坐标的顺时针旋转
    point_t ratate = {-zero.y, zero.x};     
    point_t dst = {ratate.x + center.x, ratate.y + center.y};

    output->x = dst.x/2;
    output->y = dst.y/2;

    if(DEBUG){
        printf("\n-----------------------------------------------\n");
        printf("<%s> input  :[%3d, %3d], n= %d\n",__FUNCTION__,input->x,input->y,n);
        //printf("<%s> center:[%3d, %3d]\n",__FUNCTION__,center.x,center.y);
        //printf("<%s> src:[%3d, %3d]\n",__FUNCTION__,src.x,src.y);
        //printf("<%s> zero:[%3d, %3d]\n",__FUNCTION__,zero.x,zero.y);
        //printf("<%s> ratate:[%3d, %3d]\n",__FUNCTION__,ratate.x,ratate.y);
        //printf("<%s> dst:[%3d, %3d]\n",__FUNCTION__,dst.x,dst.y);
        printf("<%s> output:[%3d, %3d]\n",__FUNCTION__,output->x,output->y);
    }
    return 0;
}
int exchange(int *p1, int *p2){
    int tmp = 0;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    
    return 0;
}
void print_matrix(int** matrix, int matrixSize, int* matrixColSize, int DEBUG){
    if(!DEBUG) return;
    int i=0, j=0;
    for(i =0; i<matrixSize; i++){
        for(j=0; j<matrixSize; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if(matrix == NULL || matrixSize<=0 || matrixColSize==NULL || matrixColSize[0]<=0) return;
    int DEBUG = 0;
    point_t input,output;

    print_matrix(matrix, matrixSize, matrixColSize, DEBUG);

    int start =0;
    int i=0, j=0;
    for(start=0; start<matrixSize/2; start++){
        i = 0;
        j = 0;
        int side = matrixSize-start;
        // down
        for(i=start, j=start; i<side; i++){
            input.x = j;
            input.y = i;
            Rotate90(&input, &output, matrixSize, DEBUG);
            exchange(&matrix[input.y][input.x],&matrix[output.y][output.x]);
        }
        print_matrix(matrix, matrixSize, matrixColSize, DEBUG);
        // right
        for(i--, j++; j<side; j++){
            input.x = j;
            input.y = i;
            Rotate90(&input, &output, matrixSize, DEBUG);
            exchange(&matrix[input.y][input.x],&matrix[output.y][output.x]);
        }
        print_matrix(matrix, matrixSize, matrixColSize, DEBUG);
        // up
        for(i--, j--; i>start; i--){
            input.x = j;
            input.y = i;
            Rotate90(&input, &output, matrixSize, DEBUG);
            exchange(&matrix[input.y][input.x],&matrix[output.y][output.x]);
        }
        print_matrix(matrix, matrixSize, matrixColSize, DEBUG);
        continue;
        // left
        for(i++, j--; j>start; j--){
            input.x = j;
            input.y = i;
            Rotate90(&input, &output, matrixSize, DEBUG);
            exchange(&matrix[input.y][input.x],&matrix[output.y][output.x]);
            print_matrix(matrix, matrixSize, matrixColSize, DEBUG);
        }
    }

}
```
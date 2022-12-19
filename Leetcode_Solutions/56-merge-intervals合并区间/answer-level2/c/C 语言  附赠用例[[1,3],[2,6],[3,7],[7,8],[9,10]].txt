1.先按start从小到大排序
2.排序完成之后，两个for循环判断a[i],a[j]是否重叠
    如果重叠，更新a[i]，(并记录有重叠的位置，之后a[i]遍历可以跳过；)继续遍历a[j],判断a[j]是否会跟最新的a[i]重叠；
    不重叠，则继续遍历a[i]


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **rslt;
    int i, j, k, q;
    int temp[2];

    //按照start排序
    for(i = 0; i< intervalsSize-1; i++) {
        for(j = i+1; j< intervalsSize; j++) {
            if(intervals[i][0]>intervals[j][0]) {
                memcpy(temp, intervals[i], sizeof(temp));
                memcpy(intervals[i], intervals[j], sizeof(temp));
                memcpy(intervals[j], temp, sizeof(temp));
            }
        }
    }

    rslt = (int**)malloc(intervalsSize*sizeof(int*));

    k = 0;

    //判断重叠
    for(i=0;i<intervalsSize;i+=q) {//跳过已经判断有重叠的位置
        q = 0;
        rslt[k] =(int*)malloc(2*sizeof(int));
        rslt[k][0] = intervals[i][0];
        rslt[k][1] = intervals[i][1];
        for(j=i+1;j<intervalsSize;j++){
            //不重叠
            if ((intervals[j][0] > intervals[i][1])) {
                break;
            }
            //重叠。更新
            if ((intervals[i][1] >= intervals[j][0])&&(intervals[i][1] <= intervals[j][1])) {                
                rslt[k][0] = intervals[i][0];
                rslt[k][1] = intervals[j][1];
                intervals[i][1] = intervals[j][1];
                q++;
            } else {
                rslt[k][0] = intervals[i][0];
                rslt[k][1] = intervals[i][1];
                q++;
            } 
        }
        k++;i++;
    }

    *returnSize = k;

    (*returnColumnSizes) = (int*)malloc(k*sizeof(int));
    for(i=0; i<k; i++){
        (*returnColumnSizes)[i] = 2;
    }

    return rslt;
}
C语言，从后往前迭代计算

int* fraction(int* cont, int contSize, int* returnSize){
    //分配内存
    int *res=(int *)malloc(16*sizeof(int));
    res[0]=1;     //分子
    res[1]=cont[contSize-1];  //分母

    for(int i = contSize-1;i>0;i--){
        //计算分子
        res[0] = cont[i-1]*res[1]+res[0];

        //因为1/x  所以换分子、分母需要互相交换
        int temp = res[1];
        res[1]=res[0];
        res[0]=temp;
    }

    //再交换一次分子分母
    int temp = res[1];
        res[1]=res[0];
        res[0]=temp;

    //必须加这句话，可能是LeetCode需要通过 returnSize来检测结果，前期我没加一直找不到原因
    *returnSize=2;
    return res;
}


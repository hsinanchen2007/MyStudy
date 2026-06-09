1.用两个指针分别移动，第一个指针指向今天的温度，第二个指针指向明天以及之后的温度，找到一个温度比今天温度高，则今天的温度找到答案；继续找下一天的温度【执行超时】
2.用一个栈保存今天的idx;(根据idx可以找到今天的温度以及方便计算后面的温度距离今天的天数)，第二天的温度如果比今天的温度高，则出栈，结果值为1;第二天的温度如果比今天的温度低，第二天的idx也进栈；直到某一天的温度，比栈顶的温度高，则栈顶出栈，根据idx，得到天数；需要一个for循环，和一个栈空间；栈空间可以动态申请TSize，或者直接用最大值；
int g_stack[30000];
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *rslt;
    int i, j, idx, num;
    int *start, *end;

    if( (T == NULL)||(TSize==0)){
        *returnSize =0;
        return NULL;
    }

    rslt = (int*)malloc(TSize*sizeof(int));
    if (rslt == NULL) {
        *returnSize =0;
        return NULL;
    }

    *returnSize = TSize; 
	g_stack[0] = 0;
	j = 0; 
    for (i=0; i<TSize-1; i++){
		idx = g_stack[j];
	    while (T[idx] < T[i+1]){//栈内值比较小的全部出栈
			rslt[idx] = (i+1)-idx;
			j--;
			if (j < 0){
				break;
			}
			idx = g_stack[j];
		} 
		j++;
		g_stack[j] = 1+i;        
    }

	//残留栈内的值，结果全部为0
	for (i=0;i<=j;i++) {
		idx = g_stack[i];
		rslt[idx] = 0;
	}

    return rslt;
}

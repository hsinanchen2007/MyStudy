1.将柱子的下标入栈（根据下标方便得到柱子高度和与下一个柱子的距离）,如果准备入栈的柱子比前一个柱子高，就有可能接雨水；
（保持栈顶的柱子，比栈内其他柱子都小，且柱子是递增的；）
2.尝试对栈顶操作出栈，然后栈中记录的第二个下标对应的柱子和准备入栈的柱子开始计算可以接多少雨水；长*宽-中间已经填满的部分；
  宽 =MIN（栈中记录的第二个下标对应的柱子，准备入栈的柱子）
  长 = 栈中记录的第二个下标开始（不包括）---->准备入栈的柱子下标结束（不包括）
  中间已经填满的部分  = 长所在区间所有 （柱子和雨水的面积）
3.接完雨水之后，将雨水填满的部分更新到高度值中，方便后面继续计算；

#define MIN(x,y)  ((x)>(y))?(y):(x)//找最小值
int calcAndUpdate(int a,int b, int min, int* height)//计算柱子和雨水的面积
{
    int rslt = 0;
    while(a<=b){
        rslt += height[a];
        height[a] = min;
        a++;
    }

	return rslt;
}

int trap(int* height, int heightSize)
{
    int *stack = NULL;
    int i, j, idx, idx1, sum, minval;

    if((height==NULL)||(heightSize==0)){
        return 0;
    }

    stack = (int*)malloc(heightSize*sizeof(int));
    if(stack == NULL){
        return 0;
    }

    j = 0;
    sum = 0;

    stack[j] = 0;
    for (i=1; i<heightSize; i++){
        idx = stack[j];

        while (height[idx] <= height[i])  {
			if (j > 0){
				idx1 = stack[j-1];
				minval = MIN(height[idx1],height[i]);
                //长*宽  -  中间柱子和雨水已经占有的面积
				sum += (i-1-idx1)*minval - calcAndUpdate(idx1+1, i-1, minval, height);
			}
            j--;
			if(j<0){
				break;
			}
            idx = stack[j];
        }
        j++;
        stack[j] = i;

    }

	free(stack);

	return sum;
}
### 解题思路
函数的返回值是处理好的矩阵

另外两个返回值通过参数列表的returnSize和returnColSize实现。
returnSize表示你返回的矩阵有几行。
returnColumSize是一个数组，表示第i行有多少个元素
二者都要另外申请内存、写入正确值

注意：参数列表中，输出参数的类型要去掉一个\*看，因为函数不能修改值，所以需要靠通过输入指针的方式来获取函数内的值。
如本题的 int\* returnSize ，虽然是整形指针，但实际上是想获得一个int类型的数。
int** returnColumSize ,虽然是一个指向指针的指针，但实际上是想获得一个一维数组，每个元素记录着一个矩阵每行的元素个数。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {

    //矩阵有returnSize个元素（每个元素还是个数组）
    *returnSize=n;
    //*returnColSize是个数组，每个元素都是int,记录的是矩阵每一行的元素数。
    *returnColumnSizes=(int*)malloc(sizeof(int)*n);
	//每行有n个元素
    int k;
    for(k=0;k<n;++k)
        (*returnColumnSizes)[k]=n;

	//要输出的矩阵共n*n个元素
	int** nums = (int **)malloc(sizeof(int*)*n);
	int i;
	for (i = 0; i < n; ++i)
		nums[i] = (int*)malloc(sizeof(int)*n);
	//row行标，col列标，step（每一圈）步骤数（计算转向和进入更小圈的时机），flag表示一个边有几个元素，FangXiang方向。
	int row = 0, col = 0, step = 0, flag = n - 1>0?n-1:1, FangXiang = 0;
	//转圈往矩阵写值
	long n_2 = n * n;
	int j;
	for (j = 0; j< n_2; ++j)
	{
		step++;
		nums[row][col] = j + 1;
		switch (FangXiang)
		{
		case 0:col++; break;//0-向右
		case 1:row++; break;//1-向下
		case 2:col--; break;//2-向左
		case 3:row--; break;//3-向上
		}
		//该转向了
		if (step % flag==0)
		{
			//改变方向
			FangXiang = (FangXiang + 1) % 4;
			//上下左右四个方向完成，转了一圈，该进入更内一层
			if(step==4*flag)
			{
				//向内一圈
				++row;
				++col;
				//每次向内一圈，边上的元素数量都会减少2.最内圈（2变1的时候）要特殊考虑一下
				flag = flag - 2==0?1:flag-2;
				//新的一圈，从新记录步骤数量
				step = 0;
			}
		}
	}

	return nums;
}
```
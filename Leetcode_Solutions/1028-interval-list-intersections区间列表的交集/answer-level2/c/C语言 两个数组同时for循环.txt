我自己的学习总结：
1.返回结果申请空间的时候，二维数组存放指针的空间要先申请，里面的一维数组的存值的空间可以根据需要申请；
2.返回的列表每个数组有几列，其实每个数组都是2列；需要一个一维数组存放即可，由于这个一维数组外面没有申请空间，所以只能传入存放这个一维数组(a[n])地址a的空间地址&a进来，将申请的空间首地址写入&a里，实现给a[n]申请空间；
将入参** returnColumnSizes看成*p,p = * returnColumnSizes; p指向的就是存放a的地址，*p就是这个地址的值；申请的空间地址要赋值给*p;然后*p这个地址空间里面存的就是数组a[n];也就是*p = a;之后依次给(*p)[n]赋值；
3.判断是要移动A数组，还是移动B数组的条件是，闭环关系结束值比较小的一个往后移动；
  闭环关系有重叠，就申请空间，记录闭环关系结果，然后移动其中一个数组；
  闭环关系不重叠，直接移动其中一个数组；

 #define MAX 1001
int** intervalIntersection(int** A, int ASize, int* AColSize, int** B, int BSize, int* BColSize, int* returnSize, int** returnColumnSizes)
{
    int i, j, k;
    int **rslt;

    rslt = (int**)malloc(sizeof(int*)*MAX);    

	k = 0;
    i = 0;
    j = 0;

    for(; (j< BSize)&&(i<ASize); ) {
        if((A[i][0] <= B[j][0])&&(B[j][0] <= A[i][1])) {                                    
            rslt[k] = (int*)malloc(sizeof(int)*2);
            
            rslt[k][0] = B[j][0];
            if (B[j][1] <= A[i][1]) {                    
                rslt[k][1] = B[j][1];
				j++;
            } else {
                rslt[k][1] = A[i][1];
				i++;
            }
            k++; 
        } else if ((A[i][0] <= B[j][1])&&(B[j][1] <= A[i][1])) {              

            rslt[k] = (int*)malloc(sizeof(int)*2);
            rslt[k][1] = B[j][1];
            if (B[j][0] >= A[i][0]) {                    
                rslt[k][0] = B[j][0];
            } else {
                rslt[k][0] = A[i][0];
            }
            k++;
			j++;
		} else if ((A[i][0] <= B[j][0])&&(B[j][1] <= A[i][1])) {
			 rslt[k] = (int*)malloc(sizeof(int)*2);
			 rslt[k][0] = B[j][0];
			 rslt[k][1] = B[j][1];
			 j++;
			 k++;		
		} else if ((A[i][0] >= B[j][0])&&(B[j][1] >= A[i][1])){
			 rslt[k] = (int*)malloc(sizeof(int)*2);
			 rslt[k][0] = A[i][0];
			 rslt[k][1] = A[i][1];
			 i++;
			 k++;
		}else if (A[i][1] < B[j][0]){                
            i++;
        } else { 
            j++; 
        }
    }

    *returnSize = k;
    *returnColumnSizes = (int*)malloc(sizeof(int)*k);
    for (i=0; i<k; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return rslt;
}

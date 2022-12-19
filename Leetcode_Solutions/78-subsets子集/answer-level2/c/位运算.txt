### 解题思路
![图片.png](https://pic.leetcode-cn.com/fb48f9ae5e6b43321329e3bc9fddce35b8627568ec92909805e951eb4f4aec87-%E5%9B%BE%E7%89%87.png)
如果n=3,二进制位于数组nums的下标的对应关系如下
000 ->
001 ->0
010 ->1
011 ->0,1
....
111 ->0,1,2
根据对应关系输出nums中的元素构造集合。
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int caculcolumnSize(int n){//计算子集所需的空间，如n=6,二进制110，所需空间return 2
    int count=0;           //n=2 ,二进制010，所需空间return 1
    while(n>0){
        if(((n>>1)<<1)==n){
            n=n>>1;
            continue;
        }else{
            n=n>>1;
            count++;
        }
    }
    return count;
}
void getnumformnums(int *nums,int *numout,int n){//组装子集numout。
    int k=0,count=0;
    while(n>0){
        if(((n>>1)<<1)==n){
            n=n>>1;
        }else{
            n=n>>1;
            numout[k++]=nums[count];
        }
        count++;
    }
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
     int inputotal=(int)pow(2.0,numsSize);
     int **output=(int**)malloc(sizeof(int*)*inputotal);
     *returnColumnSizes=(int*)malloc(sizeof(int)*inputotal);
     for(int i=0;i<inputotal;i++){
         int columnSizes=caculcolumnSize(i);//子集大小
         output[i]=(int*)malloc(sizeof(int)*columnSizes);
         getnumformnums(nums,output[i],i);//生成子集
         (*returnColumnSizes)[i]=columnSizes;
     }
     *returnSize=inputotal;
     return output;
}
```
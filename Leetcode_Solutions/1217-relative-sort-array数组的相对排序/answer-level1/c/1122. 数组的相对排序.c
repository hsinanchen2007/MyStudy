基本思路：
sort函数中实现根据arr2中的值来给arr1排序
insertsort则是把arr1剩下的数进行升序排序
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int sort(int* arry,int arrySize,int num,int k)
{
  int i,temp;
  for(i=k;(i<arrySize)&&(k<arrySize);i++){
      if(arry[i]==num){
        temp = arry[i];
        arry[i] = arry[k];
        arry[k] = temp;
        k++;
      }
  }
  return k;
}
void insertsort(int* arry,int begin,int arrySize)
{
    int j,temp;
    for(int i=begin+1;i<arrySize;i++){
      temp =arry[i];
      j = i-1;
      while(j>=begin && arry[j]>temp){
          arry[j+1]=arry[j];
          j--;
      }
      arry[j+1] = temp;
    }
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
   int i,j,k,temp;
   int* arry = (int*)malloc(sizeof(int)*arr1Size);
   for(i=0;i<arr1Size;i++){//复制arr1
       arry[i]=arr1[i];
   }
   j=0;
   for(k=0;k<arr2Size;k++){//按照arr2排序
     temp =arr2[k];
     j = sort(arry,arr1Size,temp,j);
   }
#if 1
   if(j<arr1Size){//剩下的升序排序
       insertsort(arry,j,arr1Size);
   }
   printf("%d",j);
#endif
   *returnSize =arr1Size;
   return arry;
}
```

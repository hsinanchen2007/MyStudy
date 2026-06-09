### 解题思路
此处撰写解题思路
使用冒泡排序，从尾到头对数组进行升序排列，只需要排列前k个数。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){

    int a[arrSize];
    int* result=(int*)malloc(k*sizeof(int));
    int num=0;
    *returnSize = k;

    if(k==0)return result;
    else{
        for (int i=0;i<arrSize;i++)a[i]=arr[i]; //拷贝传入的arr

        for(int i=arrSize-1;i>=0;i--)   //冒泡，从数组尾部开始，升序排列前k个数
        {
            for(int j=arrSize-1;j>arrSize-i-1;j--)
            {
                if(a[j]<a[j-1])
                {
                    int x = a[j];
                    a[j]=a[j-1];
                    a[j-1]=x;
                }
            }
            
            result[num]=a[num];
            num++;
            if(num==k)break;
        }
    }
    
    return result;
}
```
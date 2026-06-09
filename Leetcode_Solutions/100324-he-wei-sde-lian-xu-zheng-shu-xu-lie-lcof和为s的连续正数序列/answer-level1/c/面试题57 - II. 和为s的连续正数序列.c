【思路】双指针法，判断双指针内部的值之和sum是否和target一样，如果sum>target，且由于是求连续序列，那么我们从这段序列小的值开始删除，直到sum<=target为止

<![image.png](https://pic.leetcode-cn.com/fbbd9367da6b1e2c5f366aa707d8ef87a096891f85e30ea9d492f930ee2682df-image.png),![image.png](https://pic.leetcode-cn.com/7465d44639be2426d5796124c6ec58191c93577d5a220ddbc0defd19a2518c81-image.png),![image.png](https://pic.leetcode-cn.com/9fecaead15ba35427e00e21fb7ee52a7d680d8b720f27baf58801e9d5cab1e6a-image.png),![image.png](https://pic.leetcode-cn.com/0ba1eceecb27d522bb113e736c7187d0c4dafbf61c9817272efbfee4fb511e7d-image.png),![image.png](https://pic.leetcode-cn.com/3d360360c8c5a75b8bde4cc4daca06e24a20c7bd5f01b63fadb6bebefa407b93-image.png)>


```C
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int i,j,sum=0;
    int start,end;
    int **arr=(int**)malloc(sizeof(int*)*10000);
    (*returnColumnSizes) = (int*)malloc(sizeof(int)*1000);
    start=1;end=1;
    *returnSize=0;
    for(i=1;i<target;i++){
        sum+=i;end=i;
        if(target==sum){
            arr[*returnSize]=(int*)malloc(sizeof(int)*(target+1));
            for(j=start;j<=end;j++){
                arr[*returnSize][j-start]=j;
            }
            (*returnColumnSizes)[*returnSize]=end-start+1;
            (*returnSize)++;
        }
        else if(sum>target){
            while(sum>target){
                sum-=start;
                start++;
            }
            if(target==sum){
                arr[*returnSize]=(int*)malloc(sizeof(int)*(target+1));
                for(j=start;j<=end;j++){
                    arr[*returnSize][j-start]=j;
                }
                (*returnColumnSizes)[*returnSize]=end-start+1;
                (*returnSize)++;
            }
        }
    }
    return arr;
}
```

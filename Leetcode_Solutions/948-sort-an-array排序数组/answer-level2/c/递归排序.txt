/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sort(int op,int ed,int *b){
    if(op<ed){
    int js=op;//选取第一个作为基准数
    for(int i=op+1;i<=ed;i++){
        if(b[js]>b[i]){
            int tem=b[i];
            b[i]=b[js+1];
            b[js+1]=b[js];
            b[js]=tem;
            js++;
        }
    }
    sort(op,js-1,b);
    sort(js+1,ed,b);
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    int *a=(int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        a[i]=nums[i];
    }
    sort(0,numsSize-1,a);
    *returnSize=numsSize;
    return a;
}
![EBDE47B832B7476BA280621CABC29DB2.png](https://pic.leetcode-cn.com/3390df61fabe7ba075772a6ac58a365108d614832844150a637077852d1e8f5a-EBDE47B832B7476BA280621CABC29DB2.png)
### 解题思路
此处撰写解题思路
1.鸽巢原理的计数法
2.三指针法  
### 代码

```c

//void sortColors(int* nums, int numsSize){
    //1.鸽巢原理
    // int *tmp=(int *)malloc(sizeof(int)*3);
    // memset(tmp,0,sizeof(int)*3);    //必须要初始化
    // int i=0;
    // int k=0;
    // for(i=0;i<numsSize;i++)
    // {
    //     tmp[nums[i]]++;
    // }
    // for(int j=0;j<3;j++)
    // {
    //     while(tmp[j]--)
    //     {
    //         nums[k++]=j;
    //     }
    ///}
//}
void swap(int *n1,int* n2)
{
    int tmp=*n1;
    *n1=*n2;
    *n2=tmp;
}
//2.三指针
void sortColors(int* nums, int numsSize){ 
    int i=0;//首指针 ，找0
    int j=numsSize-1;//尾指针  找2
    int cur=0;   //遍历用指针
    while(cur<=j)
    {
        if(nums[cur]==0)
        {
            swap(&nums[i],&nums[cur]);   //因为左边的都已经遍历过了，满足条件的都往前走一步
            i++;
            cur++;
        }
        else if(nums[cur]==2)
        {
            swap(&nums[cur],&nums[j]);   //因为从左到右遍历，此时右边交换的还不知道值是多少，所以遍历指针不动，接着判断这个交换过来的
            j--;
        }
        else   //遇到 1的
        {
            cur++;    //继续往后走，接着重新循环判断
        }
    }

}
```
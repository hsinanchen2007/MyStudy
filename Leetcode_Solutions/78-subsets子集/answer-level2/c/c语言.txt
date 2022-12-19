![QQ图片20191220171101.png](https://pic.leetcode-cn.com/82ebcc9851e47f8cc553cd731caec76f5c8bd73aeb639f455d27db040a6e791d-QQ%E5%9B%BE%E7%89%8720191220171101.png)

```
#define Max 10000
void search(int *nums,int numsSize,int *returnSize,int**returnColumnSizes,int *digits,int length,int index,int **answer)
{
    if(index==numsSize)
    {
       answer[*returnSize]=(int*)malloc(sizeof(int)*length);
       memcpy(answer[*returnSize],digits,sizeof(int)*length);
       (*returnColumnSizes)[*returnSize]=length;
       *returnSize+=1;
       return ;
    }
    search(nums,numsSize,returnSize,returnColumnSizes,digits,length,index+1,answer);
    digits[length]=nums[index];
    search(nums,numsSize,returnSize,returnColumnSizes,digits,length+1,index+1,answer);
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
     int**answer=(int**)malloc(sizeof(int*)*Max);
     *returnSize=0;
     *returnColumnSizes=(int*)malloc(sizeof(int)*Max);
     int *digits=(int*)malloc(sizeof(int)*numsSize);
     search(nums,numsSize,returnSize,returnColumnSizes,digits,0,0,answer);
     return answer;

}
```

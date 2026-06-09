带编号从小到大对nums归并排序：
将nums数组分为若干个相邻的a和b段；
a和b都从小到大有序，暂存数组temp长度tempSize=aSize+bSize；
思路是遍历temp的每个元素，同时遍历a和b的每个元素，总是将a[j]和b[k]中较小的那个赋值给temp[i];
aSize+bSize次循环之后temp有序，再将temp赋值给同段的nums。
另外开辟numsSign和tempSign交换编号。
一开始，单个元素一定是有序的，之后两段有序数列合并成一大段有序数列，再将两段合并...直到整个数组的元素都有序。（禁止套娃）
排序的时间复杂度是O(n*log2(n))。且是稳定排序

之后从头尾同时查找：
sum=nums[j]+nums[k]
大了k-1，小了j+1
等于target之后，就将两个numsSign赋值给answer，然后返回。
因为一定有解，所以一定不会错过。
循环加入j<k则跳出的语句，可以在找不到解的时候停止。
查找操作的时间复杂度O(n)，小大取大，总的时间复杂度是O(n*log2(n))

int power2(int x){//求2的x次幂
    int result=1;
    for(int i=0;i<x;i++)
        result*=2;
    return result;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ans=(int *)malloc(sizeof(int)*2);
    int *tempSign=(int *)malloc(sizeof(int)*numsSize);
    int *temp=(int *)malloc(sizeof(int)*numsSize);
    int *numsSign=(int *)malloc(sizeof(int)*numsSize);
    *returnSize=2;
    int floor=1;
    for(int i=0;i<numsSize;i++){//初始化
        numsSign[i]=i;
        tempSign[i]=i;
        temp[i]=nums[i];
    }
    while(power2(floor-1)<=numsSize){
        for(int room=0;room<=(numsSize-1)/power2(floor);room++){
            int len=power2(floor);//len是一大段的长度
            if(room==(numsSize-1)/power2(floor))len=numsSize-room*power2(floor);
            int left=room*power2(floor),right=left+len-1,middle=left+power2(floor-1)-1;//大段一分为二
            int j=left,k=middle+1;
            for(int i=room*power2(floor);i<room*power2(floor)+len;i++){//合并有序数列
                if(k>right){
                    temp[i]=nums[j];
                    tempSign[i]=numsSign[j++];
                }
                else if(j>middle){
                    temp[i]=nums[k];
                    tempSign[i]=numsSign[k++];
                }
                else if(nums[j]<=nums[k]){
                    temp[i]=nums[j];
                    tempSign[i]=numsSign[j++];
                }
                else{
                    temp[i]=nums[k];
                    tempSign[i]=numsSign[k++];
                }
            }
        }
        for(int i=0;i<numsSize;i++){
            numsSign[i]=tempSign[i];
            nums[i]=temp[i];
        }
        floor++;
    }
    int j=0,k=numsSize-1,sum=nums[j]+nums[k];
    do{//查找target
        while(sum<target)sum=nums[++j]+nums[k];
        while(sum>target)sum=nums[j]+nums[--k];
    }while(sum!=target);
    if(numsSign[j]<numsSign[k]){
        ans[0]=numsSign[j];
        ans[1]=numsSign[k];
    }
    else{
        ans[0]=numsSign[k];
        ans[1]=numsSign[j];
    }
    return ans;
}
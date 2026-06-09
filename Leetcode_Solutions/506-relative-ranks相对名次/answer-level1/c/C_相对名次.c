### 解题思路
面向对象设计程序 建立运动员对象之后再操作

代码多，但是效率还行
![image.png](https://pic.leetcode-cn.com/10243de5e5b07d6cececb88bc4bd5d81e79df8088ad8745bcfdbdb1b9f5cbf09-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//------------------------------------------------------------运动员
typedef struct Athlete
{
    int no;
    int score;
    char* rank;
}Athlete;
//------------------------------------------------------------排序（按分数、按序号）
void sortSocer(Athlete* Nums,int Low,int High)
{
    if(Low<High)
    {
        int i=Low,j=High;
        Athlete temp=Nums[Low];
        while(i!=j)
        {
            while(i<j&&temp.score>Nums[j].score)--j;
            if(i<j)Nums[i++]=Nums[j];
            while(i<j&&temp.score<Nums[i].score)++i;
            if(i<j)Nums[j--]=Nums[i];
        }
        Nums[i]=temp;
        sortSocer(Nums,Low,i-1);
        sortSocer(Nums,i+1,High);
    }     
}
void sortNo(Athlete* Nums,int Low,int High)
{
    if(Low<High)
    {
        int i=Low,j=High;
        Athlete temp=Nums[Low];
        while(i!=j)
        {
            while(i<j&&temp.no<Nums[j].no)--j;
            if(i<j)Nums[i++]=Nums[j];
            while(i<j&&temp.no>Nums[i].no)++i;
            if(i<j)Nums[j--]=Nums[i];
        }
        Nums[i]=temp;
        sortNo(Nums,Low,i-1);
        sortNo(Nums,i+1,High);
    }
}
//------------------------------------------------------------数字转换字符串
char* toString(int Num)
{
    int stack[10],top=0;
    while(Num!=0)
    {
        stack[top++]=Num%10;
        Num/=10;
    }
    char* result=(char*)malloc(sizeof(char)*(top+1));
    result[top]='\0';
    for(int i=0;top!=0;++i)
        result[i]=stack[--top]+'0';
    return result;
}
//------------------------------------------------------------解答
char ** findRelativeRanks(int* nums, int numsSize, int* returnSize){
    //如果没有人或者一个人比赛
    if(numsSize==0)
        return 0;
    if(numsSize==1)
    {
        char** result=(char**)malloc(sizeof(char*)*numsSize);
        result[0]="Gold Medal";
        *returnSize=numsSize;
        return result;
    }

    //登记
    Athlete* athletes=(Athlete*)malloc(sizeof(Athlete)*numsSize);
    for(int i=0;i<numsSize;++i)
    {
            athletes[i].no=i;
            athletes[i].score=nums[i];
            athletes[i].rank=0;
    }
    //排名
    sortSocer(athletes,0,numsSize-1);
    //发奖
    athletes[0].rank="Gold Medal";
    athletes[1].rank="Silver Medal";
    if(numsSize>2)
    {   athletes[2].rank="Bronze Medal";    
        for(int i=3;i<numsSize;++i)
            athletes[i].rank=toString(i+1);
    }
    //回位
    sortNo(athletes,0,numsSize-1);
    //返回结果
    char** result=(char**)malloc(sizeof(char*)*numsSize);
    for(int i=0;i<numsSize;++i)
        result[i]=athletes[i].rank;
    *returnSize=numsSize;
    return result;
}
```
### 解题思路
写了三个小时、提交10次，也没写明白，自己写的hash不能用，暴力算超时。不纠结这题了，没什么意思

### 代码

```c
/*typedef struct Hash{
    float* data;
    int size;
    int dataNums;
}Hash;
Hash* newHash(int Size)
{
    Hash* hash=(Hash*)malloc(sizeof(Hash));
    hash->data=(float*)malloc(sizeof(float)*Size);
    for(int i=0;i<Size;++i)
        hash->data[i]=0.5;
    hash->size=Size;
    hash->dataNums=0;
    return hash;
}
int key(Hash* H,int Data)
{
    return Data%H->size>0?Data%H->size:(-1)*(Data%H->size);
}
int isInHash(Hash* H,int Data)
{
    return H->data[key(H,Data)]==Data;
}
void addInHash(Hash* H,int Data)
{
    H->dataNums+=1;
    H->data[key(H,Data)]=Data;
}
void delInHash(Hash* H,int Data)
{
    H->data[key(H,Data)]=0.5;
}
void freeHash(Hash* H)
{
    free(H->data);
    free(H);
}*/
//————————————————————————————————————————以上是自己写的哈希表——————以下是别人的代码
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    if(numsSize==0)
    return false;
   // if(numsSize==1)
    int mark[numsSize];//Hash表
    memset(mark,-1,sizeof(int)*numsSize);
    int i,tmp;
    for(i=0;i<numsSize;i++)
    {
        tmp=nums[i]%numsSize;//Hash函数
        if(tmp<0)//转换为正数
        tmp+=(numsSize-1);
        if(mark[tmp]==-1)//没有存数
        mark[tmp]=i;//存下数组下标
        else//已经存数
        {
            while(nums[mark[tmp]]!=nums[i])//发生冲突
            {
                tmp++;tmp%=numsSize;
                if(mark[tmp]==-1)//没有存数
                mark[tmp]=i;//存下数组下标
            }
            //已经存过该数
            if(i!=mark[tmp])
                if(i-mark[tmp]<=k)//求差值
                return true;
                else
                mark[tmp]=i;
        }
    }
    return false;
}
/*
作者：wei-ai-mai-xiao-cai
链接：https://leetcode-cn.com/problems/contains-duplicate-ii/solution/chun-cjie-jue-ying-gai-shi-mu-qian-ti-jie-li-mian-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
```
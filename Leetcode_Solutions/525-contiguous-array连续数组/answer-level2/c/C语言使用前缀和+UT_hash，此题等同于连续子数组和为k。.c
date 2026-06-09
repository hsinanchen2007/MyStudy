### 解题思路
![image.png](https://pic.leetcode-cn.com/58b3c42df28ef8c2db41f7b982f1a06bc18c41b2e36b0b0cf37d99d5cf12746e-image.png)


### 代码

```c
/* 在hash表遍历的过程中遇到两个相等的值，比如都是-3，第一个-3表示到该元素为止，多出现了3个0，
 * 第二个-3还是表示到该元素为止，多出3个0，那么这两个元素之间的0和1的个数必定相互抵消。
 * 于是，所求子串等同于，hash表中距离最远的两个相同值，复杂度o(n)*/

#define MAX(a,b) ((a) > (b) ? a:b)

typedef struct tagHASHNODE{
    int key;
    int value;
    UT_hash_handle hh;
}HASHNODE;

HASHNODE *g_hashnode = NULL;

int findMaxLength(int* nums, int numsSize){
    if(NULL == nums || 0 == numsSize)
    {
        return 0;
    }

    int sum = 0;
	
	HASHNODE *cur,*tmp;
	int ans = 0;

    //改造数组，将数组中0元素修改为-1  
    for(int i = 0;i < numsSize;i++)
    {
        if(nums[i] == 0)
        {
            nums[i] = -1;
        }
    }

    //计算前缀和,并以此作为hash的键值进行储存
    for(int i = 0;i < numsSize;i++)
    {
        sum += nums[i];
		printf("i = %d sum = %d \n",i,sum);
		//储存之前先进行查找
		HASH_FIND(hh,g_hashnode,&sum,sizeof(int),cur);
		
		if(NULL == cur)
		{
			cur = (HASHNODE*)malloc(sizeof(HASHNODE));
			cur->key   =  sum;
			cur->value =  i;
            if(0 == sum)
            {
                ans = i+1;
            }    

            printf("ans = %d\n",ans);
			//将当前节点存入hash表
			HASH_ADD(hh,g_hashnode,key,sizeof(int),cur);
		}
		else
		{
            if(0 == sum)
            {
                ans = i+1;
            } 
			//获取当前相同前缀和索引与第一次存放该索引的距离
			ans = MAX(ans,i - cur->value);
		}
		
		
    }
	
	//释放之前申请的hash节点内存
	HASH_ITER(hh,g_hashnode,cur,tmp){
		HASH_DEL(g_hashnode,cur);
		free(cur);
		cur = NULL;
	}
	
	return ans ;
}

```
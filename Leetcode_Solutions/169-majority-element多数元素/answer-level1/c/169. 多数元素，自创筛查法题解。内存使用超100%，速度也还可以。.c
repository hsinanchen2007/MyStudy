### 解题思路

说是自创，是因为我看了好多题解和评论没有人提到这个算法。下面说下这个算法的大体思路。

首先是开辟一个缓冲区用来存储筛查的过程数据，然后就是反复执行筛查的过程。

1.取nums数组的第一个数据nums[0]作为要筛查的数据
2.依次比较nums数组中剩余元素和nums[0]是否一样
3.一样计数器count加一，不一样则将数据存入缓冲区
4.交换p,q指针，对缓冲器重复上述步骤
5.直到某一个q[0]的值出现超过qlen/2

因为每次筛查都会删除一部分数据，每次删除的数据越多，后面每次筛查的时间就越短，因此输入数据中非众数成员的重复次数越少，算法的耗时越多。

![1584067926(1).png](https://pic.leetcode-cn.com/2c9f01561033036c4ee80c84e2c8eacb87dbccddb37e760776d69a1280aba5ca-1584067926\(1\).png)


### 代码

```c
int majorityElement(int* nums, int numsSize)
{
    int ret_value,count,min_value,min_idx;
    int *p,*q,plen,qlen;

    p=(int *)malloc(sizeof(int)*numsSize);
    plen=0;
    q=nums;
    qlen=numsSize;
    
    while(qlen>0)
    {   
        ret_value=q[0];
        count=0;
        plen=0;
        for(int i=1;i<qlen;i++)
        {
            if(q[i]==ret_value)
            {
                count+=1;
                if(count>=(qlen/2))
                {
                    return ret_value;
                }
            }
            else
            {
                p[plen++]=q[i];
            }
        }
        if(q==nums)
        {
            q=p;
            p=nums;
        }
        else
        {
            p=q;
            q=nums;
        }
        qlen=plen;
    }

    return ret_value;
}
```
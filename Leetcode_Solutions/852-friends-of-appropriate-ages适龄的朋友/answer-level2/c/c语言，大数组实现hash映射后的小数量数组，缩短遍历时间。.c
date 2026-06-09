### 解题思路
![image.png](https://pic.leetcode-cn.com/14ce061e2251baa44f0342392484c66b4aaa92be54fe2fc782b63b72a3992e2a-image.png)
与其说是考察数组，倒不如说是考察hash映射，实现数组大量数据的缩小化，减少遍历次数，从而轻松实现后序的暴力循环。

### 代码

```c
#define  NUM 121 //从题中的说明我们得知

int numFriendRequests(int* ages, int agesSize){
    if(NULL == ages||0 == agesSize)
    {
        return 0;
    }
    int hash_table[NUM] = {0};

    //本题的内核，映射hash
    for(int i = 0;i <agesSize;i++)
    {
        hash_table[ages[i]]++;
    }

    int countA;
    int countB;
    int totalPeople = 0;

    for(int i = 0;i < NUM;i++)
    {
        int countA = hash_table[i];
        for(int j = 0;j < NUM;j++)
        {
            int countB = hash_table[j];

            if((i <= 0.5*j +7) || (i > j) || (i>100 && j<100))
            {
                continue;
            }

            totalPeople += countA * countB;

            if(i == j)
            {
                totalPeople -= countA;
            }
        }
    }

    return totalPeople;
}
```
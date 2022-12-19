### 解题思路
![截屏2020-02-01下午3.18.35.png](https://pic.leetcode-cn.com/cf9790cbcc394c924a0cf98374fc2d09746e824b28f3d8d91f0d270f8845c490-%E6%88%AA%E5%B1%8F2020-02-01%E4%B8%8B%E5%8D%883.18.35.png)
此处撰写解题思路

### 代码

```c
#define HASH_NUM 60

int numPairsDivisibleBy60(int* time, int timeSize){
    if(time == NULL || timeSize < 1)
    {
        return 0;
    }

    int counter = 0;
    int hash_table[HASH_NUM] = {0};//创立一个hash_table;

    for(int i = 0;i < timeSize;i++)
    {
        hash_table[time[i] % HASH_NUM]++;
    }

    for(int i = 0;i <= HASH_NUM/2;i++)
    {
        if(i == 0 || i == HASH_NUM/2)//0和30的情况比较特殊，必须使用自身相加
        {
            counter += hash_table[i] * (hash_table[i] - 1)/2;//类似排列组合的c(n,2)
        }
        else
        {
            counter += hash_table[i] * hash_table[HASH_NUM - i];
        }
    }
    
    return counter;
}
```
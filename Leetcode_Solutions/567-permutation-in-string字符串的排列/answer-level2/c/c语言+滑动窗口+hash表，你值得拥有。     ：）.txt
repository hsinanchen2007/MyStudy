### 解题思路
滑动窗口 + hash表
![截屏2020-02-01上午10.42.45.png](https://pic.leetcode-cn.com/25a86ae8ad32b6c74995f2593f0e9e1c19d305a63171668ef204e1ebc7d00a5f-%E6%88%AA%E5%B1%8F2020-02-01%E4%B8%8A%E5%8D%8810.42.45.png)


### 代码

```c
#define NUM 26

bool matches(int *s1,int *s2)
{
    for(int i = 0;i < NUM;i++)
    {
        if(s1[i] != s2[i])
        {
            return false;
        }
    }

    return true;
}

bool checkInclusion(char * s1, char * s2){
    if(strlen(s1) > strlen(s2))
    {
        return false;
    }

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int s1Map[NUM] = {0};
    int s2Map[NUM] = {0};

    /*创建hash表*/
    for(int i = 0;i < len1;i++)
    {
        s1Map[s1[i] - 'a']++;
        s2Map[s2[i] - 'a']++;
    }

    for(int i = 0;i < len2 - len1;i++)
    {


        if(matches(s1Map,s2Map))
        {
            return true;
        }

        /* 创建一个子串s1长度大小的滑动窗口 ，进行右移和左移保持滑动窗口不变并且持续更新*/
        s2Map[s2[i + len1] - 'a']++;
        s2Map[s2[i] - 'a']--;
    }

    return matches(s1Map,s2Map);
}


```
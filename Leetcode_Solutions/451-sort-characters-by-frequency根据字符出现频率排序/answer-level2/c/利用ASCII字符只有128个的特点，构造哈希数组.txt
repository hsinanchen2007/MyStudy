### 解题思路
注释即思路

### 代码

```c

char * frequencySort(char * s){
    
    if(NULL == s) return NULL;
    int NUM = 128; // ascii字符的总数目128,且最大值为127
    int i = 0, j = 0;
    int freq[128] = {-1};
    int **new_freq = NULL;
    int *temp = NULL;
    int new_num = 0;
    int len = strlen(s);    // 字符串的长度
    char* ret = (char*)malloc(sizeof(char)*(len+1));
    ret[len] = '\0';
    
    // 构造freq哈希表
    while('\0'!=*s)
    {
        freq[(int)(*s)]++;
        s++;
    }

    // 取出实际的字符数目
    for(i=0; i<128; i++)
    {
        if(freq[i]!=-1)
        {
            new_num ++;
        }    
    }

    // 构造新的二维数组
    j = 0;
    new_freq = (int**)malloc(sizeof(int*)*new_num);
    for(i=0; i<128; i++)
    {
        if(freq[i]!=-1)
        {
            temp = (int*)malloc(sizeof(int)*2);
            temp[0] = i;    // 第一维是字符的ascii值
            temp[1] = freq[i]; // 第二维是出现次数
            new_freq[j] = temp;
            j++;
        }    
    }

    // new_freq数组排序，按照第二维从大到小
    for(i=0; i<new_num; i++)
    {
        for(j=i+1; j<new_num; j++)
        {
            if(new_freq[i][1] < new_freq[j][1])
            {
                temp = new_freq[i];
                new_freq[i] = new_freq[j];
                new_freq[j] = temp;
            }
        }
    }

    // new_freq数组反构造字符串
    j = 0;
    for(i=0; i<new_num; i++)
    {
        while(new_freq[i][1] && j<=len)
        {
            ret[j] = (char)new_freq[i][0];
            new_freq[i][1]--;
            j++;
        }
    }
    

    return ret;
}

















```
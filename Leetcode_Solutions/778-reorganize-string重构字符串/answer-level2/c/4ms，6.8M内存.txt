提示：
1. 只要某个字符超过字符串的一半，无法重排（考虑奇偶数）
2. 每次把出现次数最多的字符放到重排的字符串内，可以从零开始，每次累加 2，直到超出字符串的长度限制，超出限制再从 1 开始；
3. 耗费时间较多主要是每次查找出现最多的字符导致的，可以用结构体储存字符和出现的次数；但目前这种方法的好处就是数据量特别大时内存小，处理时间也不会因为数据量的变化大大增加。
```
int max_num(int * num_of_character, int size);
char * reorganizeString(char * S)
{
    int num_of_character[26] = {0};
    int len = strlen(S);
    int temp_max = 0;
    int temp_num = 0;
    char *tem_s = (char *)malloc(sizeof(char) * (len + 1));
    tem_s[len] = 0;
    for(int i = 0; i < len; i++)//统计字符串内所有字符的个数
    {
        num_of_character[S[i] - 'a']++;
    }
    int limit = (len + 1) / 2 ;
    temp_max = max_num(num_of_character, 26);
    while(num_of_character[temp_max] != 0)
    {
        if(num_of_character[temp_max] > limit)
            return ""; 
        for(int i = 0; i < num_of_character[temp_max]; i++)
        {
                tem_s[temp_num] = temp_max + 'a';
                temp_num += 2;
                if(temp_num > len - 1)//如果超出字符串边界，从序号“1”重新累加
                {
                    temp_num = 1;
                }
        }
        num_of_character[temp_max] = 0;
        temp_max = max_num(num_of_character, 26);
    }
    return tem_s;
}

int max_num(int * num_of_character, int size)//获取当前数组的最大值的序号
{
    int n = 0;
    for(int i = 1; i < size; i++)
    {
        if(num_of_character[n] < num_of_character[i])
            n = i;
    }
    return n;
}
```
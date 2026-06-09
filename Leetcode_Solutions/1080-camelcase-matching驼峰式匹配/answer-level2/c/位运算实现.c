### 解题思路
1.使用位运算先筛选出大写字母不匹配的情况。此处需要注意AAB与AB匹配的情况，通过异或可解决
2.逐步匹配pattern

![image.png](https://pic.leetcode-cn.com/61b08d96a7c403da5f96dc96c3ac33d763ca71a58e6019a1fd925a24f780ebaf-image.png)



### 代码

```c

/* 初步不考虑重复的情况 */
unsigned int get_str_upper(char *str, int len)
{
    int i;
    unsigned int tmp = 0;
	
    for (i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            tmp ^= (1 << (unsigned int)(str[i] - 'A'));
        }
    }
    return tmp;
}

int match(char *query, int query_len, char *pattern, int pattern_len)
{
    int i;
    unsigned int query_upper = get_str_upper(query, query_len);
    unsigned int pattern_upper = get_str_upper(pattern, pattern_len);
    int min_len = query_len - pattern_len;
    int match_len = 0;

    if (min_len < 0)
        return 0;

    if (query_upper != pattern_upper)	
        return 0;

    for (i = 0; i < query_len; i++)
    {
        if (query[i] == pattern[match_len]) {
            match_len++;				
            if (match_len >= pattern_len)
                return 1;		
        }
    }

    return 0;
}

int check_param(char **queries, int queriesSize, char *pattern, int *returnSize)
{
    int i;
    if (queries == NULL || queriesSize == 0 || pattern == NULL || returnSize == NULL)
        return 1;

    for (i = 0; i < queriesSize; i++) {
        if (queries[i] == NULL)
            return 1;
    }

    return 0;
}

bool *camelMatch(char **queries, int queriesSize, char *pattern, int *returnSize)
{
    int i;
    bool *result = NULL;

    if (check_param(queries, queriesSize, pattern, returnSize) == 1)
        return NULL;

    result = malloc(sizeof(bool) * queriesSize);
    if (result == NULL)
        return NULL;

    *returnSize = queriesSize;

    for (i = 0; i < queriesSize; i++) {
        if (match(queries[i], strlen(queries[i]), pattern, strlen(pattern)))
            result[i] = true;
        else
            result[i] = false;
    }
    return result;
}

```
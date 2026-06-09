### 解题思路
设Hash Table，统计字符串s中字符出现个数；再遍历t,发现一个字符，Hash对应位置-1，如果发现0位置上还需要减，返回false。
当然，长度不同的话，直接false

### 代码

```c
bool isAnagram(char * s, char * t)
{
    int Len1=(int)strlen(s);
    int Len2=(int)strlen(t);
    if(Len1!=Len2) return false;
    
     int visited[26];
    memset(visited,0,sizeof(visited));
    
    for(int i=0;i<Len1;i++)
    {
        visited[s[i]-'a']++;
    }
    for(int i=0;i<Len2;i++)
    {
        if(visited[t[i]-'a']-->0);
        else return false;
    }
    return -1;
}
```
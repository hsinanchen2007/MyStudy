### 解题思路
![QQ图片20200327222001.png](https://pic.leetcode-cn.com/2d725841456fb9757801614e6003fe458fde6f9ce7d28cd4bb1ee3dca2cde682-QQ%E5%9B%BE%E7%89%8720200327222001.png)
在哈希表中存储两个信息：一是val用于存储字母出现的次数，二是pos用于存储字母在字符串中出现的位置。
若val的值大于2次，返回-1；若val的值等于1，返回pos值最小的即可
### 代码

```c
/*暴力法超时
int firstUniqChar(char * s){
    int slen = strlen(s);
    int count;
    for(int i = 0; i < slen; i++)
    {
        count = 0;
        for(int j = 0; j < slen; j++)
        {
            if(s[i] == s[j])
                count++;
        }
        if(count == 1)
            return i;
        else
            continue;
    }
    return -1;
}*/


//哈希表
typedef struct{
    int val;
    int pos;
}map;

int firstUniqChar(char * s){
    int i, j;
    int slen = strlen(s);
    int min = slen;
    map *m = (map*)malloc(sizeof(map)*26);
    for(i = 0; i < 26; i++)
    {
        m[i].val = 0;
        m[i].pos = -1;
    }

    for(int i = 0; i < slen; i++)
    {
        m[s[i]-97].val++;
        m[s[i]-97].pos = i;
    }

    for(i = 0; i < 26; i++)
        if(m[i].val == 1 && m[i].pos < min)
            min = m[i].pos;
    
    if(min < slen)
        return min;
    else
        return -1;
}

















```
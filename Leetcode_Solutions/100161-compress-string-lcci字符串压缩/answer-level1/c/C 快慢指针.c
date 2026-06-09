### 解题思路
![image.png](https://pic.leetcode-cn.com/7c86cd2abff3ead5427c227b277eaca7b59d49dd4fb6da285d5041ed78586330-image.png)

双指针，慢指针i指向和相邻前方字母不一样的第一次出现的字母，快指针j一直向下寻找直到找到下一个和慢指针所指向字母不一样的位置，则长度即为j-i;

### 代码

```c
char* compressString(char* S)
{
    int len = strlen(S);
    int i = 0;
    int j = 0;
    int k = 0;
    if(len == 0 || len == 1)
    {
        return S;
    }
    char* new_s = (char*)malloc(len * sizeof(char));

    for(i = 0; i < len; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(S[i] != S[j])
            {
                break;
            }
        }
        if(k < len-2)
        {
            new_s[k++] = S[i];
            //下面把统计的数字转换为字符串
            int tmp = j - i;
            int intTostr[6] = {0};
            int t = 0;
            while(tmp != 0)
            {
                intTostr[t++] = tmp % 10 + '0';
                tmp /= 10;
            }
            while(t > 0)
            {
                new_s[k++] = intTostr[--t];
            }

            i = j-1;
        }
        else
        {
            return S;
        }
    }
    new_s[k] = '\0';
    return new_s;
}
```
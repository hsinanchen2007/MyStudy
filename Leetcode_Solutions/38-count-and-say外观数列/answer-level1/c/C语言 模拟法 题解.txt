
### 代码

```c
int add_string(char* res,int count,char tar,int i) // 生成字符函数，返回下标
{
    res[i] = count + 48; // 写入重复次数
    i++;
    res[i] = tar; // 写入当前元素
    i++;
    return i;
}

char * countAndSay(int n){
    char* res = (char*)malloc(sizeof(char)*10000); // 存放当前项内容
    res[0] = '1';
    res[1] = '\0';
    char s[10000] = "1"; // s存放上一项内容
    int m;
    int count = 0; // 记录单个元素的重复次数
    char* p;
    int i;
    for(i=1;i<n;i++)
    {
        p = s; // 指针回到s开头
        res[0] = '\0'; // 将返回字符串置空
        m=0; // 下标置0
        for(;*p!='\0';p++) // 遍历s，即遍历上一项
        {
            count++; // 元素出现次数+1
            if(*(p+1) == *p) // 当下一个元素与当前元素相等时重复循环
            {
                continue;
            }
            else // 当下一个元素与当前元素不等时
            {
                m = add_string(res,count,*p,m); // 为当前项字符串添加字符，改动下标
                res[m] = '\0'; 
                count = 0; // 重复次数置0
            }
        }
        strcpy(s,res); // 将当前项赋值给上一项
    }
    return res;
}
```
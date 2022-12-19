### 解题思路
统计A 动态判断L
![image.png](https://pic.leetcode-cn.com/e091ea4cb9a75875a08cad226007e41561c26a4bb8b26b90828c06023daf8868-image.png)

### 代码

```c
bool checkRecord(char * s){
    int A=0;
    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i]=='A')
            if(++A>1)
                return false;
        if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L')
                return false;
    }
    return true;
}
```
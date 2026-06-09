### 解题思路
![image.png](https://pic.leetcode-cn.com/0bacf373775164fa57d9f4cd8bfa29c0c6da106d5bd21a36dedfaf266144cd02-image.png)

连续非空格则自增

### 代码

```c
int lengthOfLastWord(char * s){
    int len=strlen(s);
    int lastwordlength=0;
    for(int i=0; i<len; i++)
    {
        int tmp=0;
        while(s[i]!=' '&&i<len)
        {
            tmp++;
            i++;
        }
        if(tmp!=0)
            lastwordlength=tmp;
    }
    return lastwordlength;
}
```
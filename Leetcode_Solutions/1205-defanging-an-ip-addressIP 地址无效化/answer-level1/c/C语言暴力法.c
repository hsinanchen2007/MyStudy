### 解题思路
![image.png](https://pic.leetcode-cn.com/9b843af6b524bdb530d055396830f891ec36541a9f1bf0a8496d48278fdb12ad-image.png)
我想请问一下为什么`sizeof`部分后的`strlen(address)`要`+7`呢

### 代码

```c
char * defangIPaddr(char * address){
    char* result=(char*)malloc(sizeof(char)*(strlen(address)+7));
    int k=0;
    int i;
    for ( i=0 ; i<strlen(address) ; i++)
    {
        if (address[i]=='.')
        {
            result[k]='[';
            k++;
            result[k]=address[i];
            k++;
            result[k]=']';
            k++;
        }
        else
        {
            result[k]=address[i];
            k++;
        }
    }
    result[i+6]='\0';
    return result;
}
```
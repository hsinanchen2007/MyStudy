### 解题思路
1.思路比较简单：遍历数组，当遇到.时，替换为[.]即可。
2.corner condition：
没有什么特殊的corner condition用例，题目收了，ip地址都是有效地址。
3.知识点总结：
没什么知识点可以复习的。
4.耗时：11mins，还行吧，一次性编码病编译通过。mark。
![image.png](https://pic.leetcode-cn.com/17cdc3fb34c8aa157bbf0c90cc241a22dfe203eb3fb66fa75c9dc0fc4b934d8a-image.png)

### 代码

```c
char * defangIPaddr(char * address){
    int i = 0;
    int j = 0;
    int len = 0;
    char *invalidIPAddr = NULL;
    len = strlen(address);
    invalidIPAddr = (char *)malloc((len + 6 + 1) * sizeof(char));
    memset(invalidIPAddr, 0x00 , (len + 6 + 1) * sizeof(char));
    for(i = 0, j = 0; i < len,j < (len + 6 + 1); i++, j++) {
        if(address[i] != '.') {
            invalidIPAddr[j] = address[i];
        }
        else {
            invalidIPAddr[j] = '[';
            j++;
            invalidIPAddr[j] = address[i];
            j++;
            invalidIPAddr[j] = ']';
        }
    }
    return invalidIPAddr;
}
```
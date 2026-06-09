### 解题思路
一次遍历取ascii字符对应的值作为整型数组下标存入整型数组，然后按先前顺序遍历该整型数组，取出个数为一的字符下标

### 代码

```c

int firstUniqChar(char * s) {
    int i=0, ret=-1;
    int arr[128] = {0};
    while (s[i]!='\0') {
        arr[s[i]]++;
        i++;
    }
    i=0;
    while (s[i]!='\0') {
        if (arr[s[i]]==1) {
            ret=i;
            break;
        }
        i++;
    }
    return ret;
}
```
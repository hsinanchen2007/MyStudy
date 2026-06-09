### 解题思路
![图片.png](https://pic.leetcode-cn.com/f8c93b58022d13ea8b9e31bc667491ad36decedf06d16ffe7792bda252949cb7-%E5%9B%BE%E7%89%87.png)

数组中保存的是字符串地址

### 代码

```c
void reverseString(char* s, int sSize){
    int i=0,j=sSize-1;
    char *temp=NULL;
    while(i<j){
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
}
```
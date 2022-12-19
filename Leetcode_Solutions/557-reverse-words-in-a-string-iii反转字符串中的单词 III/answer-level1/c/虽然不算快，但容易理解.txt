### 解题思路
![图片.png](https://pic.leetcode-cn.com/43b636ff96b6ba2ee150fc75305db111f785bd3aeda0ab6a0577289c9149ae16-%E5%9B%BE%E7%89%87.png)

### 代码

```c
void reverse(char *s,int begin,int last){
    char temp;
    while(begin<last){
        temp=*(s+begin);
        *(s+begin)=*(s+last);
        *(s+last)=temp;
        begin++;last--;
    }
}
char * reverseWords(char * s){
    int length=strlen(s);
    for(int i=0;i<length;){
        int j=i;
        while(j<length&&*(s+j)!=' ')j++;
        reverse(s,i,j-1);
        i=j+1;
    }
    return s;
}
```
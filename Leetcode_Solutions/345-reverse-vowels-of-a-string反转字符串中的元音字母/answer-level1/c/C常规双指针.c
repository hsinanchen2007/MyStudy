### 解题思路
![QQ图片20200301151857.png](https://pic.leetcode-cn.com/921ff7aa71a021eef31230fad634e58ab1b40c4bd719f0e3cc68f3d710f6ff4e-QQ%E5%9B%BE%E7%89%8720200301151857.png)
子函数判断是否为元音，双指针分别从数组头尾遍历，若两者都是元音则交换

### 代码

```c
bool isVowels(char s){
    if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='A'||s=='E'||s=='I'||s=='O'||s=='U'){
        return true;
    }else{
        return false;
    }
}

char * reverseVowels(char * s){
    char tmp;
    int sSize=strlen(s);
    int i=0,j=sSize-1;
    while(i<j){
        if(isVowels(s[i])){
            if(isVowels(s[j])){
                tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
                i++;
                j--;
            }else{
                j--;
            } 
        }else{
            i++;
        }
    }
    return s;
}
```
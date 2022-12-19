### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/4d8c0dacc590d75ebd21d6714ad992ef190ff547b83f82fb8a071e704c5056e6-image.png)

1. 所有数字字符转数字(减去'\0', 即48), '#'变成-13
2. 分段, 只需检测s[i+2]是否为-13, 就能判断出这是不是三个字符对应一个字母
3. 如果不是, 如'1' -> 'a'(此时是1), 直接加上96即可
4. 如果是, 如"10#", 此时是1 0 -13, 只需让(1*10+0) + 96即可 
### 代码

```c
char * freqAlphabets(char * s){
    int len = strlen(s);
    char *res = (char *)malloc(sizeof(char)*(len+1));
    int index = 0;


    for (int i=0; i<len; i++){ s[i] -= 48; }
    for (int i=0; i<len; i++){
        if ((i<len-2 && s[i+2]!= -13 )||i>len-3){
            res[index++] = s[i]+96;
        }
        else{
            res[index++] = 10*s[i]+s[i+1] + 96;
            i+=2;
            if (i == len-1) break;
        }
    }
    res[index] = '\0';
    return res;
}

```
![leetcode.png](https://pic.leetcode-cn.com/85ac6a2bddb3d61752aa3747db33d8c9e927bce85c7f4bd1edae4d527a0f8842-leetcode.png)

`思路是：`
`第1次遍历字符数组，将元音字母存入另一个字符数组，并将原数组中元音字符变为一个‘+’或其他字符数组中不存在的符号作为标记。`
`第2次遍历字符数组，将存储元音字母的数组元素逆序往原数组中做了标记的位置放。`
```


char * reverseVowels(char * s){
    int len = strlen(s);
    if (len <= 1)
        return s;
    char vowel[len + 1];
    int j = 0;
    for (int i = 0; i < len; i++){
        if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || 
            tolower(s[i]) == 'o' || tolower(s[i]) == 'u'){
            vowel[j++] = s[i];
            s[i] = '+';
        }
    }
    vowel[j] = '\0';
    for (int i = 0; i < len; i++){
        if (s[i] == '+')
            s[i] = vowel[--j];
    }
    return s;
}


```

`补上双指针的方法，但是效率比上面的低一些，不知道为什么，还希望大佬分析一下`
```
char * reverseVowels(char * s){
    char vowels[6] = {'a', 'e', 'i', 'o', 'u'};
    int i = 0, j = strlen(s) - 1;
    char t;
    
    while (i < j){
        if (strchr(vowels, tolower(s[i])) && strchr(vowels, tolower(s[j]))){
            t = s[i], s[i] = s[j], s[j] = t;
            i++, j--;
        }
        else if (!strchr(vowels, tolower(s[i])))
            i++;
        else if (!strchr(vowels, tolower(s[j])))
            j--;
    }
    return s;
}

```

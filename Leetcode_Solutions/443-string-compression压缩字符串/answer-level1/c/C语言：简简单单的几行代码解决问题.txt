![QQ截图20190811072703.png](https://pic.leetcode-cn.com/d0bb2921d63531b4e986cd40fa2570789d75254a2f002631920852e1031cd16b-QQ%E6%88%AA%E5%9B%BE20190811072703.png)
```
int add_num(char *str, char ch, int num) {
    if (num == 1) {//一个字符，直接写
        str[0] = ch;
        return 1;
    }else if (num < 10) {//由于1~9个字符可以直接转为字符
        str[0] = ch;
        str[1] = (char)num | 0x30;
        return 2;
    }else{              //大于9个直接用下面的函数
        sprintf(str, "%c%d", ch, num);
        return strlen(str);
    }
}
int compress(char* chars, int charsSize){
    if (chars == NULL || charsSize == 0) return 0;
    int fast = 0, slow = 0, ch_num = 1;
    for (; fast < charsSize; ++fast) {//注意：chars[charsSize] 不能读写
        if ((fast < charsSize-1) && (chars[fast] == chars[fast+1])) ++ch_num;
        else{
            slow += add_num(chars+slow, chars[fast], ch_num);
            ch_num = 1;
        }
    }
    return slow;
}
```

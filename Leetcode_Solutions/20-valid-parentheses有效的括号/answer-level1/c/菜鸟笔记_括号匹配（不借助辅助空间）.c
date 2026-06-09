### 解题思路
1. 思路简单，如果一个数组合法，则第一个出现的右括号，他的左边第一个非空字符必是它的匹配左括号。
2. 扫描过程中，每扫描到一个括号，就要检查是否为右括号。如果为右括号，向左扫描，此时会碰到两种情况'\0'，代表这里已经被置为空了，那么继续向右，直到数组越界。如果字符合法，那么字符要么匹配要么不匹配。不匹配直接返回false，否则置为'\0',此时继续从刚才的位置扫描s数组。
3. 这个题目让我学习到，要注意到数组越界判定，**每当我进行数组下标左右腾挪的时候，都要检查下标是否合法**。比如：
                while(i>=0 && s[i]== '\0'){
                    i--;
                }
此处如果不进行，i>=0判定，那么在向左扫描全是'\0'的情况下， 数组就会越界。切记注意数组越界。

### 代码

```c
bool isMatch(char ch1, char ch2){
    if (ch1 == ')' && ch2 =='(')
        return true;
    if (ch1 == ']' && ch2 =='[')
        return true;
    if (ch1 == '}' && ch2 =='{')
        return true;
    else{
        return false;
    }
    
}
bool isRight(char ch3){
    if (ch3 ==')' || ch3 == ']' || ch3 == '}')
        return true;
    else
        return false;
}

bool isValid(char * s){
    int len = strlen(s);
    int index1 = 0;
    int i;
    while(s[index1] != '\0'){//数组没有全部扫描
        if (isRight(s[index1])){//如果属于右半边括号，那么从左扫描匹配
            i = index1-1;
            if ( i == -1){
                return false;
            }
            else if (s[i] == '\0'){
                while(i>=0 && s[i]== '\0'){
                    i--;
                }
                if (i<0){//溢出
                    return false;
                }
                if (!isMatch(s[index1], s[i])){//不匹配
                    return false;
                }
                else{
                    s[index1] = '\0';
                    s[i] = '\0';
                }
            }
            else{
                if (isMatch(s[index1], s[i])){
                    s[index1] = '\0';
                    s[i] = '\0';
                }
                else{
                    return false;
                }
            }
        }
        index1++;
    }
    i = 0;
    while (len--){//看着整个数组，是否全空
        if (s[i++] != '\0'){
            return false;
        }
    }
    return true;
    
}
```
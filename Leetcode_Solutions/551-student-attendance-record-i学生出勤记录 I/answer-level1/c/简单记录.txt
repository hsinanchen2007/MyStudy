### 解题思路
#### 第一种思路
依次遍历字符串，对每一个字符进行判断。
1. 设置俩个变量，一个是a记录缺席次数，一个是l记录迟到次数 
2. 如果是P，跳过不影响，L重置为0
3. 如果是A，则A+1，并判断此时A是否大于1，是则返回false.L重置为0.
4. 如果是L，则L+1，并判断此时L是否大于2，是则返回false

#### 第二种思路
1. 使用正则匹配
2. 分别匹配字符串“A.*A”和“LLL”
3. 如果匹配到返回false

### 代码

```c
bool checkRecord(char * s){

    int A = 0;
    int L = 0;
    for(int i=0; i<strlen(s); i++){
        if(s[i] == 'A') {
            A++;
            if (A>=2){
                return false;
            }
        }
        if(s[i]=='L') {
            L++;
            if(L>2){
                return false;
            }
        }else{
            L = 0;
        }
    }
    return true;
}
```
设计三个bool型标记量：
firstUpper(第一个字母是否为大写)
othersUpper(剩余字母是否有大写的情况)
othersLower(剩余字母是否有小写的情况)

将这三个变量初始化为false。遍历字符串，根据大小写情况修改变量值，注意及时用break退出循环。

若第一字母大写，其余字母有大写有小写，返回false。
若第一字母小写，其余字母有大写，返回false。

```
bool detectCapitalUse(char * word){

    bool firstUpper, othersUpper, othersLower;
    firstUpper = othersLower = othersUpper = false;
    if (word[0] >= 'A' && word[0] <= 'Z')
        firstUpper = true;
    for (int i = 1; word[i]; ++i) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            othersUpper = true;
            break;
        }
    }
    for (int i = 1; word[i]; ++i) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            othersLower = true;
            break;
        }
    }
    if (firstUpper && othersUpper && othersLower)
        return false;
    if (!firstUpper && othersUpper)
        return false;
    return true;
}
```
![image.png](https://pic.leetcode-cn.com/139a6cbdf2147aec156c6d9a8f83fb6f32451cfe9703b4db0067d8565f7f39b0-image.png)



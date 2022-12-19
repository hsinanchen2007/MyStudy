![QQ截图20190711090020.png](https://pic.leetcode-cn.com/0e380f003ad8842271e8f60ff5bd611454ffca4ce0ea1a4a12b42a2bd0bcd4c6-QQ%E6%88%AA%E5%9B%BE20190711090020.png)

```
bool isLongPressedName(char * name, char * type){
    int name_num = 0, type_num = 0, i = 0, j = 0;
    for (; name[i] && type[j]; ++i, ++j) {
        for (name_num = 1; name[i] == name[i+1]; ++name_num, ++i);
        for (type_num = 1; type[j] == type[j+1]; ++type_num, ++j);
        if ((name[i] != type[j]) || (type_num < name_num)) return false;
    }
    return (name[i] ? false :true);//如果type字符串结束了，但是name字符串还没结束，即name字符串长于type字符串
}
```

![QQ截图20190630073539.png](https://pic.leetcode-cn.com/2dda5aeb752ca8a5bc83d6bdb92938c952ae0e41e0dace804e383b07de9904b3-QQ%E6%88%AA%E5%9B%BE20190630073539.png)

依次遍历字符串就可以了

```
bool checkRecord(char * s){
    int L_num = 0;  //字符‘L’的数量
    int A_num = 0;  //字符‘S’的数量
    for (int i = 0; s[i]; ++i) {
        if (L_num) {
            if (s[i] == 'L') {
                ++L_num;
                if (L_num > 2) return false;//只要大于2，就输出0
            } else {
                if (s[i] == 'A') ++A_num;
                L_num = 0;//只要中间不连续，就变为0
            }
        }else{
            if (s[i] == 'L') {
                L_num = 1;
            } else if (s[i] == 'A') {
                ++A_num;
            }
        }
    }
    return (A_num > 1 ? false : true);
}
```







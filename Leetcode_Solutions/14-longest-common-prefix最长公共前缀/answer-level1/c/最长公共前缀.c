### 解题思路
本题最大的阻碍是处理这类测试用例：
    ["aaaaa","aa","aaa"]

关键在即使有字符串与common比较全部匹配，内层的j循环借宿后都要在common的j处赋值'\0'，即 common[j]='\0'; 其中j正好为strlen(strs[i])+1。
如图：
![1.png](https://pic.leetcode-cn.com/e99ac6e058d1d81a023866cb759efe5dd4f9ac23916687c4a4ddc7415ea8c8f2-1.png)

以上面的测试用例为例，common的长度为5，此时与之比较的str[1]的长度为2，那么内层j循环结束后j的值为3了，请注意这一点一定要想明白！
为什么是3请参考[C语言for循环（for语句）详解](http://c.biancheng.net/view/1811.html)，注意j++是什么时候执行的。


另外参考了别人的题解发现居然可以直接用'\0'来标识字符串结束，这是我开始没有想到的。基础知识不牢靠啊。

[一道题目玩转指针数组和二级指针](http://c.biancheng.net/view/vip_2021.html) 这篇文章写得真的好！
### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) return "";
    char *common;
    common = *strs;
    int i,j;
    for(i=1;i<strsSize;i++){
        for(j=0;j<strlen(strs[i]);j++){
            if(common[j]!=strs[i][j]){
                common[j]='\0';
                break;
            }        
        }
        common[j]='\0';
    }
    return common;
}
```
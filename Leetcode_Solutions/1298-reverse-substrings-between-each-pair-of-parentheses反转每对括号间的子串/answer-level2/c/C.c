### 解题思路
暴力法：
1. 记录字符串中左右括号的下标位置和个数
2. 从内到外，依次反转一堆括号中的字符
3. 新建一个内存，存储删掉括号的字符串，返回

### 代码

```c
char * reverseParentheses(char * s){
    if(!s) return NULL;//空值返回
    int len = strlen(s);
    int left[1000];//因为字符串的长度最大2000
    int right[1000];
    //获取括号的位置和个数
    int i = 0, leftindex = 0, rightindex = 0;
    while(s[i]){
        if(s[i] == '('){
            left[leftindex++] = i;//按顺序记录下左括号的下标位置，leftindex既是下标，又充当括号个数
            //printf("第%d个(的位置：%d\n",leftindex, left[leftindex-1]);
        }
        if(s[i] == ')'){
            right[rightindex++] = i;
            //printf("第%d个)的位置：%d\n",rightindex, right[rightindex-1]);
        }
        i++;
    }
    //从内层括号开始反转：分奇/偶数次反转 s[left[index - i]]~s[right[i]]
    i = 0;
    leftindex--, rightindex--;//恢复下标
    while(i <= leftindex){
        //寻找当前左括号右边的第一个右括号
        int offset = 0;//存在()(((())))这种场景，左右括号不能简单对应
        while(right[offset] < left[leftindex - i]) 
            offset++;
        int sright = right[offset] - 1;//左括号右边第一个字母
        int sleft = left[leftindex - i] + 1;//右括号左边第一个字母
        right[offset] = -1;//左括号下标用完即销毁，否则一直在用第一个右括号
        //printf("left = %d, right = %d\n", sleft, sright);
        while(sleft <= sright){
            char tmp = s[sleft];//字符串反转，就是左右两端对换
            s[sleft] = s[sright];
            s[sright] = tmp;
            sleft++, sright--;
        }
        i++;
    }
    //去掉括号
    int reslen = len - 2 * ++leftindex;
    char* res = (char *)malloc((reslen + 1) * sizeof(char));//注意字符串长度+1，必须有末尾的'\0'作为字符串的结束标志
    memset(res, '\0', (reslen + 1) * sizeof(char));//初始化，重点在于结束标志
    int j = 0;
    i = 0;
    while(s[i]){
        if(s[i] != '(' && s[i] != ')'){
            res[j] = s[i];
            //printf("%c   ", res[j]);
            j++;
        }
        i++;
    }
    return res;
}
```
### 解题思路

[参考：表驱动法](https://leetcode-cn.com/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/)

参考第一位的大佬java写的状态机，不优雅，边界情况处理得比较丑, 只能说好在容易理解。

表的行程过程实际我也不太明白， 但是理解了一下，可以自己按照这个规则写出来。

小数点后的数字是单独的一种状态（3）。只有（3）和（6）可以吸收e（4），即e后面的数字单独进入一个状态（吸收一个+/-的7）（5）。

所有状态吸收到other字符后都会变成false状态（-1）。

基本状态：blank（0），数字（6），正负号（1），小数点（2）。

衍生状态：小数点后的数字（3），数字后有e（4），e后有正负号（7），e后的数字（5）。

退出状态：所有吸收other的状态，以及（3,5,6）状态后面的blank（8，合法退出）

注意第一位和最后一位的边界条件，以及至少保证有一个数字。

### 代码

```cpp
int transfer[9][6] = 
    {
    {0,1,6,2,-1,-1},
    {-1,-1,6,2,-1,-1},
    {-1,-1,3,-1,-1,-1},
    {8,-1,3,-1,4,-1},
    {-1,7,5,-1,-1,-1},
    {8,-1,5,-1,-1,-1},
    {8,-1,6,3,4,-1},
    {-1,-1,5,-1,-1,-1},
    {8,-1,-1,-1,-1,-1}
    };

int getnext(char c){
    
    if(c==' '){
        return 0;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else if(c<='9'&&c>='0'){
        return 2;
    }
    else if(c=='.'){
        return 3;
    }
    else if(c=='e'){
        return 4;
    }
    else {
        return 5;
    }
}

class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        int nextchar = getnext(s[0]);
        int last=-1;;
        switch (nextchar)
        {
        case 0: // 首位为空
            last = 0;
            break;
        case 1: // 首位为正负号
            last = 1;
            break;
        case 2: // 首位为数字
            last = 6;
            break;
        case 3:  // 首位为小数点
            last = 2;
            break;
        case 4: // 首位为e
            last = 5;
            break;
        case 5: // 首位为其他
            last = -1;
            break;
        }

        int now = last;
        bool flag = true;
        bool have_digit = false; // 必须要有一个数字
        /* 首位检查 */
        // printf("init with %c:%d  init state = %d \n",s[0], nextchar, last);
        if(last == 5) return false; // 不允许以e开头
        if(last==6) have_digit = true; // 如果第一个就是数字
        if(last == -1) return false; // 如果第一位就是其他
        for(int i=1;i<len;i++){
            int nextchar = getnext(s[i]);
            if(nextchar==2){
                have_digit = true; // 至少有一个数字
            }
            now = transfer[last][nextchar];
            // printf("%c:%d from %d to %d \n",s[i],nextchar,last,now);
            if(now == -1){ // 经过-1状态就退出
            flag = false;
            break;
            }
            last = now;
        }
        /* 最后一位检查 */
        if(now == 4 || now == 7){
            flag = false; // 最后一位为e, 最后一位为+/-
        }
        return flag&&have_digit;
    }
};
```
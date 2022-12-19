### 解题思路
`bool`型数组`dp[i][j]`代表从`s[i]`到`s[j]`是不是最长回文子串，
更新方法见【核心代码】：
```c
    if(s[i]!=s[j])dp[i][j] = false;
    else if(i+1>j-1)dp[i][j] = true;
    else dp[i][j] = dp[i+1][j-1];
```
但是注意这种方法不能按行更新dp数组，比如更新`dp[0][3]`时需要获取`dp[1][2]`的值，而这个值以按行顺序尚未更新，所以我们按照对角线方向去更新dp数组（详见代码第二个for循环）。

不过，这种更新dp数组的方法似乎不太高效，本代码能通过测试样例，但用时只击败了5%的用户。

#### 算法更新：
我好像发现了为什么此程序用时不佳了，看了大佬的代码，发现dp数组更新方式和我一样，只不过人家初始状态多了一些：
【我的dp数组初始状态】dp[i][i]=true // 对角线上全为true（单个字符组成的串肯定是回文串）
【大佬的dp数组初始状态】
dp[i][i]=true   //对角线上全为true
dp[i][i+1]=true if s[i]==s[i+1]  //连续的两个相同字符组成的字符串也是回文串

这样做的好处就是，上面【核心代码】的部分只用一行就能搞定，不需要分情况讨论。

### 代码

```c
#include<string.h>

#define maxn 1005

bool dp[maxn][maxn];    // dp[i][j]记录的是s[i]到s[j]的串是不是回文子串
char result[maxn];  // 直接定义足够大的存发结果的数组

char * longestPalindrome(char * s){
    // char result[maxn];  // 不能在这定义，不然返回的result是空的
    // char * result = NULL;    //不能像这样先定义空指针，再让它指向用malloc分配的空间(不删放着提醒自己)
    int LengthofResult, start, end;
    if(strlen(s)==0){   // 易忽略部分，如果输入的是空字符串，则下述三个for循环都进不去，所以需要专门返回一个空字符串作为结果，不然会输出上一个测试用例的结果
        result[0] = '\0';
        return result;
    }
    for(int i=0;i<strlen(s);i++){
        dp[i][i] = true;
    }
    // for(int i=0;i<strlen(s);i++){    // 此题按行初始化dp数组是错误的，要按对角线初始化dp数组
    //     for(int j=i;j<strlen(s);j++){
    //         if(s[i]!=s[j])dp[i][j] = false;
    //         else if(i+1>j-1)dp[i][j] = true;
    //         else dp[i][j] = dp[i+1][j-1];
    //     }
    // }
    for(int low=0;low<strlen(s);low++){   // 和主对角线平行的若干条线，从主对角线开始，往右上角平移遍历
        for(int i=0,j=low;i<strlen(s)-low;i++,j++){
            if(s[i]!=s[j])dp[i][j] = false;
            else if(i+1>j-1)dp[i][j] = true;
            else dp[i][j] = dp[i+1][j-1];
        }
    }

    for(int up=0;up<strlen(s);up++){    // 和主对角线平行的若干条线，从最右上角元素开始，向左下角平移遍历，直到遍历完主对角线
        for(int i=0,j=strlen(s)-1-up;i<=up;i++,j++){
            // printf("(%d, %d) %d\n", i, j, dp[i][j]);
            if(dp[i][j]==true){
                LengthofResult=j-i+1;
                start = i;
                end = j;
                // break;   // 注意break只能跳出一层循环
                for(int k=0;k<LengthofResult;k++){
                    result[k] = s[start++];
                }
                result[LengthofResult] = '\0';  // 这一行容易忽略，因为所有测试用例共享这个数组，所以需要明确当前测试用例输出结果的末尾在哪
                return result;
            }
        }
    }
    return result;  // 象征性地写一句return，不然会报错
}
```
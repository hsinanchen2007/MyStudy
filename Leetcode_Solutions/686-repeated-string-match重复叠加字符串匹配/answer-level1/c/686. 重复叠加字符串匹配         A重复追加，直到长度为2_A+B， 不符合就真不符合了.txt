### 解题思路
给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 -1。

举个例子，A = "abcd"，B = "cdabcdab"。

答案为 3， 因为 A 重复叠加三遍后为 “abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B 并不是其子串。


### 代码

```c
int repeatedStringMatch(char * A, char * B){
    int i, j = 0, k, cnt = 1;
    
    #if 1
//暴力法
    //情况太多，只能把B里字符一个个与A里循环比较。 批量比较strcmp strstr都考虑不周
    //有种例子"aabaa"   "aaab"； 故需要挨个从A里开始试
    for (k = 0; A[k]; k++) {
        if (A[k] == B[0]) {
           i = k;
           j = 0;
           cnt = 1;
            while (A[i] == B[j]) {
                i++, j++;
                if(B[j] == '\0')    return cnt;
                //A遍历完了，cnt加1，继续重新比较
                if(A[i] == '\0') {
                    cnt++;
                    i = 0;
                }
            }
        }
    }
    #else
    //反复叠加A，  直到A字符串长度超过 2*A + B， B还不是字串就不是字串了
    //自己最开始认为三遍A肯定够了，但是B可以是10次重复。所以把B的长度加上就可以了。

    #endif
        
    return -1; 
}
```
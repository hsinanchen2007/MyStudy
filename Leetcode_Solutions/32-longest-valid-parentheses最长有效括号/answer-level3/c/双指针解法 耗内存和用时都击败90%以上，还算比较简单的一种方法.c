想到一个双指针解法，比较简单
首先分析下题目：
符合要求的子串应该满足哪些条件：
**1.左右括号个数相同**
**2.从左往右数，右括号的个数不能比左括号多**，比如 ())()( ,这种虽然左右括号个数相同，但仍然不满足要求
**3.从右往左数，左括号的个数不能比右括号多**，比如 ((())
只要满足上面三个条件那么这个子串一定是符合要求的，必要充分条件。

**为方便计算，再将左右括号量化一下，左括号记为1，右括号记为-1**，将字符串转化为-1 1组成的数组，比如"(())"转化为数组a就是 1 1 -1 -1;这样一来，条件2 3 都可以用求和来判断了，比如条件2，就可以从左往右求和，求到第i个数的时候，如果为负，表明此时多了个‘)’,算是一个小技巧
执行结果还不错
![image.png](https://pic.leetcode-cn.com/896fd2dee79d7d598eb6e578ac34b1e37fd0ea1a26de115230125d310d9a237f-image.png)

算法代码如下：
```
int longestValidParentheses(char * s){
    int sLenth = strlen(s);
    int L = 0;
    int R = sLenth - 1;
    int j = 0;
    int i = R;
    int sum = 0;
    int maxLen = 0;

    int *a  = (int*)malloc(sizeof(int) * (sLenth + 1));
    for(int i = 0; i < sLenth; i++) {
        if(s[i] == '(') {
            a[i] = 1;
        }
        if(s[i] == ')') {
            a[i] = -1;
        }
    }

    while(L < R) {
        if(a[L] == -1)
            L++;
        if(a[R] == 1)
            R--;
        if((a[L] == 1) &&(a[R] == -1)) {
            for(j = L; j <= R; j++) {
                sum+= a[j];
                if(sum < 0) {//不满足条件2
                    if(maxLen < (j-L)) {
                        maxLen = j-L;
                    }
                    L = j + 1;
                    sum = 0;
                    break;
                }
            }
            if((j == R + 1) && (sum > 0)) {
                sum = 0;
                for(i = R; i >= L; i--) {
                    sum += a[i];
                    if(sum > 0) {//不满足条件3
                        if(maxLen < (R - i)) {
                            maxLen = R - i;
                        }
                        R = i - 1;
                        sum = 0;
                        break;
                    }
                }
            }
            if(((j == R + 1) || (i == L - 1)) && (sum == 0)) {//满足条件1 2 3，符合有效子串要求
                if(maxLen < (R - L + 1)) {
                    maxLen = R - L + 1;
                }
                break;
            }
        }
    }
    return maxLen;
} 
```


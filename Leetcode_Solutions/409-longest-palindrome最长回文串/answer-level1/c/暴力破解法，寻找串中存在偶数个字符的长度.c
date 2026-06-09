### 解题思路
此处撰写解题思路

### 代码

```c
//获取当前位置，回文串长度
int getPalindromeLength(char * s, int pos, int length)
{
    //偶数长度的回文串
    int evenNum = 0;
    int i = 0;
    for(i; pos-i>=0 && pos+i+1<= length-1; i++) {
        if (s[pos-i] != s[pos+i+1]) {
            break;
        }
    }
    evenNum = i*2;

    //奇数回文串
    int oddNum = 0;
    i = 0;
    for(i; pos-i-1>=0 && pos+i+1<=length-1; i++) {
        if (s[pos-i-1] != s[pos+i+1]) {
            break;
        }
    }
    oddNum = i>0 ? i*2+1 : 0;

    return evenNum > oddNum ? evenNum : oddNum;
} 

int longestPalindrome(char * s){

    //获取字符串最大回文串长度
    // int length = strlen(s);
    // if (length <= 1) {
    //     return strlen(s);
    // }

    // int max = 0;
    // for(int i = 0; i<length-1; i++) {
    //     int temp = getPalindromeLength(s, i, length);
    //     printf("%d %d %d\n", i, length, temp);
    //     if (temp > max) {
    //         max = temp;
    //     }
    // }
    // return max;

    //统计字符个数为偶数的数量
    int length = strlen(s);

    //循环处理，如果发现相同的字符，用0替换，方便后面统计
    for(int i=0; i<length; i++) {
        if (s[i] == '0') {
            continue;
        } else {
            for(int j= i+1; j<length; j++) {
                if (s[j] == '0') {
                    continue;
                } else {
                    if (s[i] == s[j]) {
                        s[i] = '0';
                        s[j] = '0';
                        break;
                    }
                }
            }
        }
    }

    //统计能构成回文串的字符个数
    int num = 0;
    for(int i=0; i<length; i++) {
        if (s[i] == '0') {
            num++;
        }
    }

    //最大回文串数量，分两种情况
    if (num == length) {
        return num;
    } else {
        return num+1;
    }
}
```
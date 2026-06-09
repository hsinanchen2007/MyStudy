### 解题思路
char c，个数为偶数，则所有c都是最长回文串中内容
个数为奇数num，则num - 1个c是最长回文串中内容
这样之后就剩下若干个个数为1的char，则这些char中随意挑一个组成最长回文串

### 代码

```c

int longestPalindrome(char * s){
    int nums[128] = {0};
    int i = 0;
    int len = strlen(s);
    for (i = 0; i < len; i++) {
        nums[s[i]]++;
    }

    int ret = 0;
    int flag = 0; //有奇数则为1
    for (i = 0; i < 128; i++) {
        if (nums[i] % 2 == 0) {
            ret += nums[i]; 
        } else {
            ret = ret + nums[i] - 1;
            flag = 1;
        }
    }

    if (flag == 1) {
        ret++;
    }
    return ret;
}
```
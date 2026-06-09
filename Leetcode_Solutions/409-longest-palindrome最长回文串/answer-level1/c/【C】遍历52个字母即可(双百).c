### 解题思路
回文字符串可以理解为对称的字符串，即除中间字母外，其余字母出现次数必为偶数；
1、遍历输入字符串，找出每个字母出现的次数
2、计算偶数字符串个数，若有奇数则记录flag，最终长度+1(可放在中间))
![image.png](https://pic.leetcode-cn.com/afac09f5c4c182095037814df0b51aca0697acf4e5abd6d3fbb3e726a39ad51e-image.png)

### 代码

```c
int longestPalindrome(char * s){
    int len = 0;
    int flag = 0;
    int num[52] = {0};
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            num[s[i] - 'a']++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            num[s[i] - 'A' + 26]++;
        }
    }
    for (int i = 0; i < 52; i++) {
        len += num[i] / 2 * 2 ;
        if (num[i] % 2) {
            flag++;
        }
        if (num[i] != 0) {
        }
    }
    
    len = flag ? len + 1 : len;
    return len;
}
```
### 解题思路
关键点是处理中间空格，两头空格很好处理。
1. 除去头部空格，while循环，s++就搞定了。（这里可能全是空格，所以删除光）
2. 取除末尾空格，使用`strlen`函数得到字符串长度，同时判断`s=''`的情况即可。（也就是将修改后的s求长度）
通过上面两步得到的字符串首尾都是无空格的，然后翻转一下就可以了。
3. 中间空格处理和单词处理：遇到多余空格就是**搬！**
    + 首先，我们从左到右扫描字符串，因此遇到的肯定是第一个空格，那么直接进行局部翻转单词操作。
    + 然后就看是否连续空格出现，这时就判断`s[i+1]`后面是不是重复空格，然后一个劲往字符串后面**搬**。因为可能中间很多重复空格，所以要搬动很多次，则while循环解决。
    + 搬完后，那么`s[i+1]`一定是第一个单词打头，所以用`idx=i+1`记录下这个单词开始，方便之后找到它进行翻转即可。（更新操作）

而在搬空格这里搞点技巧，每搬动一次，字符串长度`len-1`，且将字符串末尾的`'\0'`前移动一位，就是下面函数的`trimSpace`的do-while循环。

`a good***example`：
翻转：`elpmaxe***doog*a`
局部翻转：example*，然后删除后面多余的两个空格(**),所以最后问题就是，最后一个单词，他没有空格结束，因此对最后单词再翻转下,也就是为什么保留字符串长度的原因啦。

下面图片展示：

<![幻灯片1.PNG](https://pic.leetcode-cn.com/7face05a38f6e05c186d9b4547aa6828d2d8b879d19f54385b440f892ff53ff4-%E5%B9%BB%E7%81%AF%E7%89%871.PNG), ![幻灯片2.PNG](https://pic.leetcode-cn.com/18febe032486bf1b1e30dc28bae21603c374b4e293246295e75a08d286d6e107-%E5%B9%BB%E7%81%AF%E7%89%872.PNG), ![幻灯片3.PNG](https://pic.leetcode-cn.com/9111b10538f520f866a214a7f232bdba2b5f7347bf645da85cf54bc4cd2ede1d-%E5%B9%BB%E7%81%AF%E7%89%873.PNG), ![幻灯片4.PNG](https://pic.leetcode-cn.com/43971359e90257ce4dcff38316f398b532d2854f7a5885cded68268ca68443d9-%E5%B9%BB%E7%81%AF%E7%89%874.PNG), ![幻灯片5.PNG](https://pic.leetcode-cn.com/20f97ee1cd386cf6bb06047e064a64d648887800053888babfb84a05639c7482-%E5%B9%BB%E7%81%AF%E7%89%875.PNG), ![幻灯片6.PNG](https://pic.leetcode-cn.com/00ec4a8ce8d4c2c34e8188897712713f30345aa72b03677e9867ccecf703f872-%E5%B9%BB%E7%81%AF%E7%89%876.PNG), ![幻灯片7.PNG](https://pic.leetcode-cn.com/efdba577ce75c924e0b21cb9555605a4ffa3daf9b32865c8d77cc98259a7084c-%E5%B9%BB%E7%81%AF%E7%89%877.PNG), ![幻灯片8.PNG](https://pic.leetcode-cn.com/a6125cefa3f2847c9d5b32df0f7b53091bda5e938963fdf13c35720d5a14aa5b-%E5%B9%BB%E7%81%AF%E7%89%878.PNG), ![幻灯片9.PNG](https://pic.leetcode-cn.com/aee7351a3923c808f9b270594974592df277c3a49f6e47803d67a1beae5c03da-%E5%B9%BB%E7%81%AF%E7%89%879.PNG), ![幻灯片10.PNG](https://pic.leetcode-cn.com/2d3f09c5bed870295052b3d89245b8e66b1460194417092200bd1fb7f00c263b-%E5%B9%BB%E7%81%AF%E7%89%8710.PNG), ![幻灯片11.PNG](https://pic.leetcode-cn.com/9d54859344dc25fb2bff0a0ae5332ffe963a221c0328777fdd1c4677306dcc26-%E5%B9%BB%E7%81%AF%E7%89%8711.PNG), ![幻灯片12.PNG](https://pic.leetcode-cn.com/b8bbe8e6ebc79d151225a9b51c513894e0ef0eb1f2e81f8f2428137db7c3553d-%E5%B9%BB%E7%81%AF%E7%89%8712.PNG), ![幻灯片13.PNG](https://pic.leetcode-cn.com/35f73fb004aed799325bce7fe3f43aa6fdfdbbebd2b61f91c4504adc485ab8db-%E5%B9%BB%E7%81%AF%E7%89%8713.PNG)>

### 代码

```c
void reverse(char *s, int start, int end) {
    char temp;
    while (start < end) {
        temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

void trimSpace(char *s, int start) {
    // 将中间多余的空格移到最后，同时把字符串结束符\0向前搬一个
    do {
        s[start] = s[start+1];
        start++;
    } while (s[start]);  // 在字符串结束符停止
}

char * reverseWords(char * s){
    // 1.消除前面多余空格
    while (*s == ' ') s++;
    // 2.消除后面的空格，且长度-1
    int len = strlen(s) - 1;
    if (len < 0) return s;
    while (s[len] == ' ') {
        s[len] = '\0';
        len--;
    }
    reverse(s, 0, len);  // 整体翻转

    // 3.消除中间多余空格并反转局部
    int i, idx = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {  // 遇到空格表示单词结束
            reverse(s, idx, i - 1);  // 注意区间[idx,i-1]是单词
            // 准备删除第二个空格
            while (s[i+1] && s[i+1] == ' ') {
                trimSpace(s, i + 1);
                len--;  // 修改字符数组长度
            }
            idx = i + 1;  // 最后idx移到新的单词开头这里
        }
    }
    // 处理最后单词
    reverse(s, idx, len);
    return s;
}
```

虽然上面在去除s末尾空格，可以不用维护`len`长度，因为最后单词结束时，i肯定指向第一个`\0`，所以最后翻转可以使用`reverse(s, idx, i-1);`

**看完点赞，腰缠万贯，🤭**
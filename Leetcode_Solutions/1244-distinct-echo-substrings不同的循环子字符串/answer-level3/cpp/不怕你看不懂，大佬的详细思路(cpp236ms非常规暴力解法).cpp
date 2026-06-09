- 看了一下大佬 [@wnjxyk](/u/wnjxyk/) 的b站视频，觉得写得不错就自己打了一份，附上详细注释和思路。
- 先放一个他视频的网址，讲的很详细：
> https://www.bilibili.com/video/av83044577?p=2

---

## 分析：
- 这道题的数据规模不大，因此我们可以暴力枚举每一个子字符串，但是我需要将比较子字符串是否相等放在O(1)的时间复杂度内。
- 不过好像正常判断也能过，比赛时认为一定会超时就没写。。。。。。。
- 我们把前i个字符哈希在一个最大为n的数组中(n是text长度，i在0-1之间)

## 代码：

```cpp
#define ULL unsigned long long // 相当于取模，2^64，因为有可能会溢出，所以溢出后相当于取了一次模
const int MAX = 2050; // 设置最大值，要大于2000
const ULL CHASH = 37; // 我们会将text每一位上的字符转成37进制的数
ULL hCode[MAX], hSqr[MAX]; // hcode用于保存前n位的字符串哈希值，可以理解为前缀和。hsqr是37的幂，防止后面再算一遍，所以我们保存在一个数组中。

class Solution {
public:
    set<ULL> table; // 为什么要用table？因为如果有两个字符串是一样的但实际还是一个，比如实例1的abcabc。
    int distinctEchoSubstrings(string text) {
        table.clear();
        int n = text.size();
        hCode[0] = 0; // 相当于一个哨兵，方便循环内的计算，所以我们的第一位是从1开始的
        hSqr[0] = 1; // 37的零次方等于1
        for (int i = 1; i <= n; i++) {
            hCode[i] = hCode[i-1] * CHASH + text[i-1]; // 一开始是37的0次方乘以第一位，到了第二位，那就是37的1次方乘以第一位加上37的0次方乘以第二位，37转10进制。
            hSqr[i] = hSqr[i-1] * CHASH; // 累乘37的幂，不解释。
            /*
                这里说一下为什么要用到hSqr这个数组，假设字符串abcabc，第一个a是37的0次方乘以a，而第二个a是37的3次方乘以a，那这样哈希出来的值肯定不等，
                所以我们要把前面次方低的乘以37的3次方，这样就相等了，同理b和c也一样。那3次方是怎么来的呢？我们发现其实就是你分开来的两个子字符串的长度，
                比如abc就是3个。
            */
        }
        for (int i = 1; i <= n; i++) {
            ULL curCode = 0; // 这个值用于记录以i开头的字符串的哈希值如果我们发现这个字符串可以串联，就把它放进table里。为什么要这样同样也是为了避免重复计算。
            for (int j = i; j <= n; j++) {
                curCode = curCode * CHASH + text[j-1]; // 不停的计算新的当前字符串。
                int len = j - i + 1; // 拿到子字符串的长度
                int st = j + 1, en = j + len; // 计算右边的字符串的开始和结束位置。开始很明显是j+1开始的，结束下标是j+len是因为len是长度，我要从j+1开始数，数len个。
                if (en > n) break; // 如果左边的字符串的结束位置超过二分之一下标，右字符串不成立，并且之后的字符串也不成立，直接break
                ULL left = (hCode[j] - hCode[i-1]) * hSqr[len]; // 计算左边的哈希值，别忘了加上前面说的要补全的次幂。
                ULL right = hCode[en] - hCode[st-1]; // 右边本来是高次幂，不用补全。
                /*
                    这里说一下为什么两个开始位置要减一，我们通过前缀和计算区域数组（一维数组）中的值时，不能把开始下标的值给减了，否则算的和就少了开始位置的值
                    这里也是一样，只不过我们是前缀哈希值，不是前缀和。
                */
                if (left == right) table.insert(curCode); // 相等就放进table中
            }
        }
        return table.size(); // table的长度就是答案。
    }
};
```

- 我自己又写了一遍，基本一样但要比上面的慢。

```cpp
#define ULL unsigned long long

class Solution {
public:
    set<ULL> table;
    int distinctEchoSubstrings(string text) {
        table.clear();
        int n = text.size();
        ULL hCode[n+1], hSqr[n+1];
        hCode[0] = 0;
        hSqr[0] = 1;
        for (int i = 1; i <= n; i++) {
            hCode[i] = hCode[i-1] * 37 + text[i-1];
            hSqr[i] = hSqr[i-1] * 37;
        }
        for (int i = 1; i <= n; i++) {
            ULL curCode = 0;
            for (int j = i; j <= n; j++) {
                curCode = curCode * 37 + text[j-1];
                int len = j - i + 1;
                int st = j + 1, en = j + len;
                if (en > n) break;
                ULL left = (hCode[j] - hCode[i-1]) * hSqr[len];
                ULL right = hCode[en] - hCode[st-1];
                if (left == right) table.insert(curCode);
            }
        }
        return table.size();
    }
};
```
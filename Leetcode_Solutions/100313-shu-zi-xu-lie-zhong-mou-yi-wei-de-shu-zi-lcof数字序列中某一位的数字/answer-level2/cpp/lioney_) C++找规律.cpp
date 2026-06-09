`我们首先来分析自然数序列和其位数的关系，前九个数都是1位的，然后10到99总共90个数字都是两位的，100到999这900个数都是三位的，那么这就很有规律了，我们可以定义个变量cnt，初始化为9，然后每次循环扩大10倍，再用一个变量len记录当前循环区间数字的位数，另外再需要一个变量start用来记录当前循环区间的第一个数字，我们n每次循环都减去len*cnt (区间总位数)，当n落到某一个确定的区间里了，那么(n-1)/len就是目标数字在该区间里的坐标，加上start就是得到了目标数字，然后我们将目标数字start转为字符串，(n-1)%len就是所要求的目标位，最后别忘了考虑int溢出问题，我们干脆把所有变量都申请为长整型的好了，参见代码如下：`
```
class Solution {
public:
    int findNthDigit(int n) {
        long len = 1, cnt = 9, start = 1;
        while(n > len * cnt) {
            n -= len * cnt;
            len ++;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1) / len;     // 第n位所在的数
        string num_str = to_string(start);
        return num_str[(n-1) % len] - '0';
    }
};
```

#### 思路
对于读取n个字符的问题，主要有四种情况：
1. file 的长度小于 n，如: "abcdef", 20
2. file 的长度卡在`read4`边缘情况1 如: "abcdef", 5
3. file 的长度卡在`read4`边缘情况2 如: "abcdef", 7
4. file 的远大于n 如: "abcdef", 3

为了简化问题，希望把上述四种情况中的前三种合并在一起。我的思路是：去读取`n+4`个字符。这样对于读取`n`个字符的问题，就通过检查文件是否足够长，就可以将问题切分成两部分：
- 如果够长，直接返回`n`
- 如果不够长，就返回`n`和`len`（文件长度）中较小的一个

#### 代码
```cpp []
int read(char *buf, int n) {
    char *src = new char[4];
    int len = 0, _st = 4;
    while(_st == 4 && len < (n + 4)) {
        _st = read4(src);
        memcpy(buf + len, src,  _st * sizeof(char));
        len += _st;
    }
    if(read4(src) == 0) {
        return min(n, len);
    }
    return n;
}
```

#### 备注
其实并不确定是不是简化了问题，说不定是弄巧成拙了，期望各位提出宝贵建议~
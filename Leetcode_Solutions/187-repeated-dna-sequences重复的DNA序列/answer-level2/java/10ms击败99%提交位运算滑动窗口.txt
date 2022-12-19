这道题看起来似乎跟位操作一点关系都没有，但是注意读题，里面有两个关键的限定条件——**10个字母长的序列**和**只有“ACGT”四个字符**，看到这两个条件就联想到一个`int`数字有32位，所以一个`int`数字就能够正好代表这样的一个10个字符长的序列。

在实现中我们用

* `00`代表`A`
* `01`代表`C`
* `10`代表`G`
* `11`代表`T`

比如序列`AAAAACCCCC`就可以用`00 00 00 00 00 01 01 01 01 01`来表示，这只是从右到左的20位，更高位都是`0`省略掉了。

一串DNA正好需要20位，高位直接用掩码去掉。每一个唯一的DNA串都能用一个唯一的`int`数字表示，用一个数组来表示每一串出现的次数，数组最大长度是`1<<20`。

```java
public List<String> findRepeatedDnaSequences(String s) {
    if (s == null || s.length() <= 10) return new ArrayList<>();
    char[] chars = s.toCharArray();              // 转化成数组提高效率
    int[] freq = new int[1<<20];                 // 出现频率数组
    int num = 0;                                 // 计算过程中的int值
    int mask = (1<<20)-1;                        // 掩码，只保留最低的20位
    for (int i = 0; i < 10; i++) {               // 初始化第一个DNA串
        num <<= 2;
        if (chars[i] == 'C') {
            num |= 1;
        } else if (chars[i] == 'G') {
            num |= 2;
        } else if (chars[i] == 'T') {
            num |= 3;
        }
    }
    freq[num]++;
    List<Integer> repeated = new ArrayList<>();
    for (int i = 10; i < chars.length; i++) {    // 遍历所有的长度为10的DNA串
        num <<= 2;                               // 清楚最高的两位，也就是移除滑出的字符串
        if (chars[i] == 'C') {
            num |= 1;
        } else if (chars[i] == 'G') {
            num |= 2;
        } else if (chars[i] == 'T') {
            num |= 3;
        }
        num &= mask;                             // 掩码 保留最低的20位
        freq[num]++;                             // 统计出现频率
        if (freq[num] == 2) repeated.add(num);   // 只有出现次数是2的时候才计入，避免重复
    }

    List<String> res = new ArrayList<>(repeated.size());
    for (Integer integer : repeated) {           // 将int数字转化成DNA串
        char[] seq = new char[10];
        for (int i = 9; i >= 0; i--) {
            switch (integer&3) {
                case 0:seq[i]='A';break;
                case 1:seq[i]='C';break;
                case 2:seq[i]='G';break;
                case 3:seq[i]='T';break;
            }
            integer >>=2;
        }
        res.add(new String(seq));
    }
    return res;
}
```
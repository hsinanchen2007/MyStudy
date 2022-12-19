### 1156. 单字符重复子串的最大长度 Medium
参考了mike-meng的想法，丰富了例子

> 1.使用total数组记录下每个字符出现的总次数
2.用left数组记录索引i(其对应的时*arr[i]*)位置的左边从0开始到i位置出现的连续重复字符的个数
用right数组记录从len-1到i位置出现的连续重复字符的个数，记录最长的重复字符的个数（不出现aaabccc这种case时的）
3.arr[i]的左边left[i-1]和arr[i]的右边right[i+1]的对比：
total[i-1]>left[i-1] -->result = max(result,left[i-1]+1)
如abaaacddd中 i=6时为c，total[6-1] =4 left[6-1] =3 4>3 可以把第0个a与c交换或与b交换，abaaacddd-->baaaacddd
同理，total[i+1]>right[i+1]-->result = max(result,right[i+1]+1)
如abaaacddded i=6为c total[6+1]=4 right[6+1]=3 4>3 可以把第10个d与第9个e进行交换，abaaacddded-->abaaacdddde
如果出现arr[i-1]=arr[i+1] & arr[i-1]!=arr[i] 这时需要判断total[i-1]与left[i-1]+right[i+1]的大小，
相等的话，证明只能此left[i-1]的开头拿走字符或是从right[i+1]的结尾拿走字符
如aaacaaaa 如i=3时为c,要想组成最长的连续单一字符，需要从前面部分[0-2] 或是后面部分[4-7] 拿走a与c进行调换aaacaaaa--->caaaaaaa
不相等的话，说明其他的地方有空余
如abaaacaaaa 如i=5时为c，第0个a与第5个c进行调换abaaacaaaa-->cbaaaaaaaa 
```
public int maxRepOpt1(String text) {
    char[] chas = text.toCharArray();
    int len = chas.length;
    int[] total = new int[26];
    int[] left = new int[len];
    int[] right = new int[len];
    for (int i = 0; i < len; i++) total[chas[i] - 'a']++;
    int result = 1;
    int cnt = 1;
    left[0] = 1;//初始化left
    for (int i = 1; i < len; i++) {
        if (chas[i] == chas[i - 1]) cnt++;
        else cnt = 1;
        left[i] = cnt;
        result = Math.max(result, left[i]);
    }
    cnt = 1;
    right[len - 1] = 1;//初始化right 
    for (int i = len - 2; i >= 0; i--) {
        if (chas[i] == chas[i + 1]) cnt++;
        else cnt = 1;
        right[i] = cnt;
        result = Math.max(result, right[i]);
    }
    for (int i = 1; i < len - 1; i++) {
        if (total[chas[i - 1] - 'a'] > left[i - 1]) {
            result = Math.max(result, left[i - 1] + 1);
        }
        if (total[chas[i + 1] - 'a'] > right[i + 1]) {
            result = Math.max(result, right[i + 1] + 1);
        }
        if (chas[i - 1] == chas[i + 1] && chas[i - 1] != chas[i]) {
            if (total[chas[i - 1] - 'a'] > (left[i - 1] + right[i + 1])) {
                result = Math.max(result, left[i - 1] + right[i + 1] + 1);
            } else {
                result = Math.max(result, left[i - 1] + right[i + 1]);
            }
        }

    }
    return result;
}
```

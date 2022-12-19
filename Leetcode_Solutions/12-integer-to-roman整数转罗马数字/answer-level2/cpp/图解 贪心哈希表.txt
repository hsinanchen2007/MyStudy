

### 思路一：贪心

贪心法则：**我们每次尽量使用最大的数来表示。** 比如对于 1994 这个数，如果我们每次尽量用最大的数来表示，依次选 1000，900，90，4，会得到正确结果 `MCMXCIV`。

所以，我们将哈希表按照从大到小的顺序排列，然后遍历哈希表，直到表示完整个输入。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/65b3af737cb0fe6552981b580e65586b03976c854d9f1fe1e51bb6731eb96dbc-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/a8f1eccf2846927c62c56a4f6cf840e9beffe8d2f64c5f8c6a4379b22dc755b6-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/a14b7ccdb82258a795e8a469f6e62bbdaca128f88419789b37b5987788ba5e2a-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/022e3966f886466375920196e68bf4d757a9d7234328d16a80a295dea4be4cc9-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/44d8122bc1a4839db7891c86bf87457fc216eca1e89d606e0f663140b0e5f8d4-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/357058450781f54659bf1f4e88706dc297c96e44a923a54e664b8b0b79ded021-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/b1a56088d415ad79c333d9b7ab3cfbafe158c4314e09967a7822f60c3cbbcace-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/5cc3eb04be4e8a7313310249ab5debb346c7a557dad980479532c551b5c4311c-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/dd91187fa3a10833df27a0280983bc49b208dda86241685772ee9939a75faacc-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/3d56ad33596a2811b8af17a9406bb1b8352f4ab07544079a28d02902e3870e4e-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/fba6adb68745804dcda090b117d0f9727c95d8a1e7dec06d44fa11dd23f84bd8-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG),![幻灯片12.JPG](https://pic.leetcode-cn.com/f1a9c22284d460e08d86bdfa9862c126c7b9d4d6cc50587a3f12bc31eff49297-%E5%B9%BB%E7%81%AF%E7%89%8712.JPG),![幻灯片13.JPG](https://pic.leetcode-cn.com/493fea258b9b1373e3101d0e22736b9dfd6b90160923a9f2124a6bf73813b093-%E5%B9%BB%E7%81%AF%E7%89%8713.JPG),![幻灯片14.JPG](https://pic.leetcode-cn.com/97bda51245d82c8e9a12455c24a97d9500a687a85ed5abed3e059c727d4c75f9-%E5%B9%BB%E7%81%AF%E7%89%8714.JPG)>

### 代码

```python []
class Solution:
    def intToRoman(self, num: int) -> str:
        # 使用哈希表，按照从大到小顺序排列
        hashmap = {1000:'M', 900:'CM', 500:'D', 400:'CD', 100:'C', 90:'XC', 50:'L', 40:'XL', 10:'X', 9:'IX', 5:'V', 4:'IV', 1:'I'}
        res = ''
        for key in hashmap:
            if num // key != 0:
                count = num // key  # 比如输入4000，count 为 4
                res += hashmap[key] * count 
                num %= key
        return res

```

```c++ []
class Solution {
public:
    string intToRoman(int num) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string reps[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res;
        int 
        for (int i = 0; i < 13; i ++ )  //这里不使用图里的count了，一遍一遍来就行了
            while(num >= values[i])
            {
                num -= values[i];
                res += reps[i];
            }
        return res;
    }
};
```
### 复杂度分析
- 时间复杂度：$O(1)$。最坏条件下，循环的次数为哈希表的长度。
- 空间复杂度：$O(1)$。

### 思路二：暴力匹配
这个思路相对比较简单，因为题目中说输入在 1 ~3999 的范围内，所以我们把 1 到 9，10 到 90，100 到 900，1000 到 3000 对应的罗马数字都表示出来，最后对于任何输入，我们要做的就是把找到的罗马数字组合起来即可。

比如输入是 `2359`，我们找到 `2000`，`300`，`50`，`9` 对应的罗马数字为 `MM`，`CCC`，`L`，`IX`，组合后得到结果为 `MMCCCLIX`。
```python []
class Solution:
    def intToRoman(self, num: int) -> str:
        M = ["", "M", "MM", "MMM"] # 1000，2000，3000
        C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"] # 100~900
        X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"] # 10~90
        I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"] # 1~9
        return M[num//1000] + C[(num%1000)//100] + X[(num%100)//10] + I[num%10]
```

```c++ []
string intToRoman(int num) {
    string table[4][10] = { // 1~9
                           {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                            // 10~90
                           {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                            // 100~900
                           {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, 
                            // 1000~3000
                           {"", "M", "MM", "MMM"} 
                          };
    string result;
    int count = 0;
    while(num > 0){
        int temp = num % 10;
        result = table[count][temp] + result;
        num /= 10;
        count++;
    }
    return result;
}
```
### 复杂度分析
- 时间复杂度：$O(1)$。
- 空间复杂度：$O(1)$。

这个方法相当于牺牲了一部分空间复杂度换取了时间复杂度，因此运行时间更快。

如有问题，欢迎讨论~
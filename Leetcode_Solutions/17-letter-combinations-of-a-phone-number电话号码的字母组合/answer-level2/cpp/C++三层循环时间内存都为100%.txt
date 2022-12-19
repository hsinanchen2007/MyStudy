没想到三层循环能偶尔做到两个100%，感觉可能是判题标准不太严谨，重复提交了几次，其中有一次的结果还算正常，4ms，8.3M；

使用三层循环来解决的话先是各层循环的轮数：
第一层循环轮数：数字字符串digits的长度；
第二层循环轮数：当前数字对应的字母个数；
第三层循环轮数：上一轮结果容器的元素个数；

三层循环的思想在于，每当增加一个数字，其对应的字母有N个（N=3或N=4）的话，就重新指定容器的长度为原来的N倍，并使用空字符串""填充空位置；并且在上一次的结果中分别追加这N各字符，即可得到结果；

下面是详细的算法流程
- 初始化一个空容器res；
- 如果传入字符串为空，则返回空容器res；
- 定义一个字符串容器存储各个数字对应的字母str = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
- 在res中插入一个空字符串""；
- 第一层循环，控制条件为变量i小于字符串digits的长度；
    - 读取字符串digits的第i个字符，并获取其ASCII码值num，并令num减去48再减2，ASCII码值减去48即可得到当前数字，减去2是为了使数字直接和str容器的索引对应起来，用“数字”来当索引；
    - 获取当前res的元素个数count；
    - 构造一个新容器keep=res；
    - 将res容器重置大小到str[num].size() * count，使用空字符串""填充空位置；
    - 第二层循环，控制条件为变量j小于str[num].size()，即数字对应的字母个数；
        - 第三层循环，控制条件为变量k小于结果容器res上一次的元素个数count；
            - 令res[j * count + k] = keep[k];即将res的元素先分别置为上一次结果中的元素；
            - 令res[j * count + k] += str[num].at(j);并在res元素后面追加当前数字对应的各个字母；
- 返回结果即可。

代码：
```C++ []
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) {
            return res;
        }
        vector<string> str = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            char ch = digits[i];    //第i个字符
            int num = (int)ch - 48 - 2;     //字符对应的ASCII码值，并对应到数组的索引处
            int count = res.size();
            vector<string> keep = res;
            res.resize(str[num].size() * count, "");
            for (int j = 0; j < str[num].size(); j++) {
                for (int k = 0; k < count; k++) {
                    res[j * count + k] = keep[k];
                    res[j * count + k] += str[num].at(j);
                }
            }
        }
        return res;
    }
};
```

代码效果：
![mcmy-leetcode-p17-res3.png](https://pic.leetcode-cn.com/c85d641ab951c9f6cd8127b0269f16cc45903a996258f0b4b1b79d7775eb7531-mcmy-leetcode-p17-res3.png)

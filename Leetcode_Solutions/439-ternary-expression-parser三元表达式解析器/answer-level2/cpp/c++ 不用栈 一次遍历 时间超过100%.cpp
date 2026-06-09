
我自己的话，第一感觉就是直接遍历，完全翻译了我自己人脑翻译三元编译器的思路。
首先从字符串最左侧开始读取信息，第一位一定是T或者F。
如果是T，下一位一定是？，直接从下两位开始考虑最终的结果。
如果是F，需要找到当前三元运算符对应的冒号，从冒号之后的地方开始考虑最终的结果。找的过程里记录一下？出现的次数，每次出现：则将该次数减1，直到次数为零，则找到了对应的冒号。从这之后开始考虑，应该就是迭代版的递归。
需要注意一些边界条件，比如如果下一位是冒号，或者当前位置是最后一个字符了，应该直接返回答案了。
如果题目没有限定数字范围为0-9的话，还要再麻烦一点。


![Screen Shot 2020-02-10 at 3.19.57 PM.png](https://pic.leetcode-cn.com/043a41e6e141c18b34ebdbb8bb63b849881cf2c3e204aa244d3b138d031558df-Screen%20Shot%202020-02-10%20at%203.19.57%20PM.png)


[自己动手实现分布式缓存](https://github.com/wfnuser/burrow)
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
欢迎大家在github follow我 对分布式缓存感兴趣的可以看第一个项目，希望之后可以发布更多的玩具项目

```
class Solution {
public:
    string parseTernary(string expression) {
        int index = 0;
        while(true) {
            char tf = expression[index];
            if (tf == 'T') {
                if (index+1 >= expression.size() || expression[index+1] == ':') return "T";
                index++;
                index++;
            } else if (tf == 'F') {
                if (index+1 >= expression.size() || expression[index+1] == ':') return "F";
                int cnt = 0;
                while(true) {
                    index++;
                    if (expression[index] == '?') {
                        cnt++;
                    }
                    if (expression[index] == ':') {
                        cnt--;
                    }
                    if (cnt == 0) {
                        index++;
                        break;
                    }
                }
            } else {
                string ans(1, tf);
                return ans;
            }
        } 

        return "";
    }
};
```

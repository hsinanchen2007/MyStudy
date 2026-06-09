&emsp;其实，作为我这种算法小白做做算法题，总是容易没找对方向，然后乱码一通。
&emsp;实际上，优秀的思路比乱码一通有效多了。
&emsp;最开始这个题目我一看比较懵，看他像二维矩阵，想利用二维矩阵来做，但是实际上有点笨，感觉没有领悟到这题的内核。
&emsp;实际上所有算法题都是用语言把一个算法，一个思路，一个过程给**隐蔽化了**,所以在日常训练的过程中，我觉得得更注意如何发现算法更深层次的部分，这才是练之有用的办法。
### 思路一，利用goto周期性循环
&emsp; 以上是我的一些小感悟，在做这题的时候，刚开始没思路，但是实际上核心很简单**如何利用简单的方法（少量的遍历），来构造并获得结果**。实际上在我做了大致100+的题目之后，我发现字符串的模拟题大致都是找到**一个规律**，和**一个临界条件**。
&emsp; 这题的规律是什么呢？ 答案当然不是LeetCode说的啥$"Z","N"$型，而在于这个字符串他有点像一个**震荡**的电磁波,也就是具有周期性，而且其与周期有关的参数就是所给的$numRows$。这就是在观察题干中所发现的。
&emsp; **接下来就只有两个问题了：**
- 第一， 如何依据周期性构造
- 第二， 如何将构造后的转为结果

&emsp;有了明确的问题就相对性容易有不错的思路了。
&emsp;**解题思路如下:**
&emsp;①： 初始化一个$vector<string>$，用来存储利用周期性规律得到的结果。
&emsp;②： 经过规律发现我们可以把每个↓,↑的过程当成一个周期，比如题目中的P,A,Y,P就是一下一上。
&emsp;③： 利用string重载了$+$操作符的性质获得结果
```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows == 0 || numRows == 1) return s; \\ 特判一下，写题时多提醒自己
        int cnt = 0;
        string ans;
        vector<string> ss(numRows,"");
        while (1){ \\ 一整个周期
            for (int i = 0; i < numRows; ++ i){ \\ ↓ 的过程
                if (cnt < s.size()) ss[i] += s[cnt];
                else goto loop;
                ++ cnt;
            }
            for (int i = numRows-2; i >= 1; -- i){ \\ ↑的过程
                if (cnt < s.size()) ss[i] += s[cnt];
                else goto loop;
                ++ cnt;
            }
        }

    loop:for (auto& e : ss) ans += e; \\ 假如遍历完毕，goto跳到这，获得答案
        return ans;
    }
};
```




### 思路二， 优化减少冗余循环
&emsp;在写完之后思考，应该如何才能把规律统一起来呢(物理学家不也是一直希望建立一个统一场嘛，哈哈，(*^▽^*))。我也想我的代码不要分成两种情况，一种情况就能解决，于是我便继续找规律(也正是这种探索，我觉得才能提升自己)。
&emsp;这里就动手写了写，利用$cnt$取模来更新$i$值,且去掉了$while$循环，减少了$for$循环的个数。

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows == 0 || numRows == 1) return s; \\ Special case judgment ！！！
        int cnt = 0;
        string ans;
        vector<string> ss(numRows,"");

        
        for (int i = 0;; ++ i){ \\ One cycle ↑ && ↓
            int loc =  i < numRows ? i : 2*numRows - 2 - i; \\ Decide whether it's ↑ or ↓
            if (cnt < s.size()) ss[loc] += s[cnt];
            else break;
            ++ cnt;
            if (cnt % (2*numRows-2) == 0) i = -1; \\ Determine if it's entering a new cycle
        }

        for (auto&e : ss) ans += e;
        return ans;
    }
};
```
&emsp;最后，题解添加了很多冗余元素，主要是为了还原自己思考的过程，希望给自己些感悟。如何才能快而准的找到解题思路，水平有限，如有错误望指正(*^▽^*)
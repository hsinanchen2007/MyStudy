整体思路，动态规划，从后往前扫，初始条件F(n) = 1，一个数字时只有一种翻译方式

具体到题目上，先将原数字转成字符串，从倒数第二个字符开始向前扫
假设当前字符和后一个字符构成的字符串为s，有两种情况：

情况一：当前数字可以和后面一个数字组合，即"10"<= s <= "25"
    这种情况下，当前翻译数F(i) = F(i+1) + F(i+2)
    有点像斐波那契数列和跳台阶那个题

情况二：当前数字不能和后面一个数字组合，即s<"10 或s>"25
    这种情况下，当前翻译数F(i) = F(i+1)
    就是说不能和后面一个组合的话，前面即使加上这个数字，也不会增加翻译方法

代码里用了一个vector来记录不同位置的翻译数量。这里有个需要注意的地方在于，vector的长度比原数字长度多了1
    这是为了统一处理边界条件。

代码如下：
```
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int len = s.length();
        if(len<2)
            return 1;
        vector<int> vi(len+1, 0);
        vi[len] = 1;
        vi[len-1] = 1;
        for(int i=len-2;i>-1;i--){
            string cur="";
            cur.push_back(s[i]);
            cur.push_back(s[i+1]);
            if(cur<="25"&&cur>="10")
                vi[i] = vi[i+1] + vi[i+2];
            else
                vi[i] = vi[i+1];
        }
        return vi[0];
    }
};
```

上面用了个vector，因为和数字等长，所以额外空间其实并不多，但如果数字巨长，或者直接给个超长的数字字符串的话，
空间复杂度就高了。这里还能再优化一下，因为每次计算F(i)，只需要F(i+1)和F(i+2)，所有用三个变量来存放每次的数据
```
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int len = s.length();
        if(len<2)
            return 1;
        int left=0, mid=1,right=1;
        for(int i=len-2;i>-1;i--){
            string cur="";
            cur.push_back(s[i]);
            cur.push_back(s[i+1]);
            if(cur<="25"&&cur>="10")
                left = mid + right;
            else
                left = mid;
            right = mid;
            mid = left;
        }
        return left;
    }
};
```


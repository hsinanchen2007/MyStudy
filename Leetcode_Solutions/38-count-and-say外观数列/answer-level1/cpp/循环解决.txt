初学c++，就想着使用while循环可以解决这个问题，就把res的值不停改变，下一次调用while循环体就会使用新的res，循环次数由n决定。
```
class Solution
{
public:
    string countAndSay(int n)
    {
        string res = "1"; // 初始值为"1"
        while (--n) // 这边要循环n-1次，所以用--n，第一次循环的值已经是n-1的值了，如果n=1，就不进入循环，直接输出答案了
        {
            int len = res.size(), j = 0, count = 0;
            string tmp;                   // 初始化一个临时字符串
            for (int i = 0; i < len; ++i) // 设置i和上面的j都作为下标用于访问res里的字符，前面的count作为计数用
            {
                if (res[i] == res[j])
                    ++count; // 刚开始循环的时候，j是第0个，i是第0个，肯定相等，至少有一个1，后续i开始变化，如果还相等，就会加到count里
                else
                {
                    tmp += ('0' + count); // '0'加上count就是count的字符串形式，其实count不会超过9就。。这样写没问题，但是如果count超过10就要换写法了
                    tmp += res[j];        // 这边j还是没改变过的，是之前count计数的那个数字
                    j = i;                // 然后令j=i，i已经变成新的那个数字了
                    count = 1;            // 因为i已经是新的数字就不会过到前面的if里，就要让count重置为1，因为肯定有一个这个数嘛
                }
            }
            tmp += ('0' + count); // 最后一次没写进来，这边就是写入最后一个count和数字
            tmp += res[j];
            res = tmp; // 把res赋值成tmp就好了，下次再循环就是新的res了
        }
        return res;
    }
};
```

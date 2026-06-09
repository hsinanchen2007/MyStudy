### 解题思路
一个非常暴力的思路：我们去记录s和t中每个字母出现的次数，如果t中字母出现的频率大于s，我们求其差就是我们要转换的次数。那么t中的字母出现频率小于s是什么情况呢？就是说t中其他要被替换的字母会把这一部分补上。例如样例1中t->a:2 b:1,s->a:1 b:2，我们这里做的是把a减少一个。同样的b就会增加一个达到题目要求
时间复杂度：O(n)
### 代码

```cpp
class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        int a[250]={0};
        int b[250]={0};
        int sum=0;
        for(int i=0;i<=n-1;i++)
        {
            a[s[i]]++;
            b[t[i]]++;
        }
        for(int i=97;i<=122;i++)
        {
            if(b[i]>a[i])
            {
                sum+=b[i]-a[i];
            }
        }
        return sum;
    }
};
```
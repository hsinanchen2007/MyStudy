# 思路：
若一个数是非快乐数，那么一直计算下去必定会出现循环，找到这关键点就得出答案。用set保存中间出现的数，一旦出现重复的数且不为 1，那么此数就是非快乐数！
```C++ [-C++]
bool isHappy(int n) {
        unordered_set<int> s;
        int t;
        while (n!=1)
        {
            t = n;
            n = 0;
            while (t)
            {
                n += (t % 10) * (t % 10);
                t = t / 10;
            }
            if (s.count(n) != 0)//出现重复的数
                return false;
            s.insert(n);
        }
        return true;
    }
```

只要所有元素数目的公约数有大于2的即可。
先算出任意一个数目的所有约数，然后对其他数目而言，检查这些约数是否是公约数，不是则踢掉。最后看是否还有大于2的约数。

其实更直接的办法是，计算所有数目的最大公约数，检查它是否大于1。这个代码在官方题解就有，很简单。这里贴的是上面的方法的代码，因为涉及到一些STL基本用法比较多，就贴出来就一下。
```
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cnt;
        for(int d : deck) ++cnt[d];
        vector<int> divisor;
        unordered_map<int, int>::iterator it = cnt.begin();
        float sqr = sqrt(float(it->second));
        for(int candidate = 2; (float)candidate < sqr; ++candidate) {
            if(it->second % candidate == 0) {
                divisor.push_back(candidate);
                divisor.push_back(it->second / candidate);
            }
        }
        if(it->second > 1) {
            if(sqr == (int)sqr) divisor.push_back((int)sqr);
            divisor.push_back(it->second);
        }
        set<int> used;
        used.insert(it->second);
        for(++it; it != cnt.end(); ++it) {
            if(used.find(it->second) != used.end()) continue;
            for(int i = 0; i < divisor.size(); ++i) {
                if(it->second % divisor[i] != 0) {
                    divisor.erase(divisor.begin() + i);
                    --i;
                }
            }
            if(divisor.empty()) return false;
            used.insert(it->second);
        }
        return !divisor.empty();
    }
};
```

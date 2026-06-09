### 解题思路
我又来了，套了丑数二的方法，使用数组管理指针，甚至比上题的代码更简洁。思路是一样的，只是这题的发展方向是不定的，但是还是一个数组搞定，手动滑稽。

### 代码

```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        set<int> res={1};
        vector<set<int>::iterator> points;
        for(int i=0;i<primes.size();i++){ //初始化
            points.push_back(res.begin());
        }
        while(res.size()<n)
        {
            int temp=INT_MAX;
            for(int i=0;i<primes.size();i++)     temp=min(temp,*points[i]*primes[i]); //找最小数
            res.insert(temp);
            for(int i=0;i<primes.size();i++)    if(temp==*points[i]*primes[i]) points[i]++; //更新指针，因为可能多个指针都更新了，所以要这样写。
        }
        return *res.rbegin();
    }
};
```
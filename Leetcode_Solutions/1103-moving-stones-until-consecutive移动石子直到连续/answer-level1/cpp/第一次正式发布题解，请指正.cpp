执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.3 MB, 在所有 C++ 提交中击败了100.00%的用户

思路：分析，最多的移动次数是空位数，最少的得看是否连续，只有0 1 2三个值
1.先将三数进行排序
2.再判断三数是否连续，接着判断是否两两连续

```reasonml
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        //1.是否连续，连续则返回0,0 2.不连续则计算空位数
        int imin=0,imax=0;
        vector<int> v;
        int m_max=max(max(a,b),c),m_min=min(min(a,b),c),m_mid=a+b+c-m_max-m_min;

        if(m_max-m_min>2){
            imax=m_max-m_min-2;
            if(m_max-m_mid<3 || m_mid-m_min<3)
                imin=1;
            else
                imin=2;
        }

        v.push_back(imin);
        v.push_back(imax);
        return v;
    }
};
```

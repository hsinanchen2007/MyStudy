### 解题思路
效率略低，执行用时击败7.21%；
记忆化递归：用map保存中间值。

### 代码

```cpp
class Solution {
public:
    map<int, int> w;//记忆化递归，保存中间值
    vector<pair<int, int> > re;
    static bool cmp(pair<int, int> a, pair<int, int> b){
        if (a.first != b.first) return a.first<b.first;
        else return a.second<b.second;
    }
    int getKth(int lo, int hi, int k) {
        //逐个计算权重，然后排序，最后找第k个
        for (int i=lo; i<=hi; i++){
            re.push_back(pair<int, int> (get_weight(i), i));
        }
        sort(re.begin(), re.end(), cmp);
        return re[k-1].second;
    }
    int get_weight(int x){
        if (x==1) return 0;
        if (w[x]!=0) return w[x];
        if (x % 2==0) w[x]=get_weight(x/2)+1;
        else w[x]=get_weight(3*x+1)+1;
        return w[x];
    }
};
```
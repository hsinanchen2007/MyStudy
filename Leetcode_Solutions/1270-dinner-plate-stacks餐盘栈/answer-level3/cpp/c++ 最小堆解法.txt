### 总体思路
1、用一个最小堆维护当前最左边（`index`最小）的非空栈。
2、每次 pop/popAtIndex 操作维护最大非空栈的 index. 

### (1) pop/popAtIndex 删除元素
1、每次 pop 操作后，如果使得最后一个非空栈变空，则不断减小当前最大非空栈的 index，直到遇到非空栈或到达边界，相当于“删除”了这些空栈。 总共耗时：O(n). n指总操作数。这是因为：
（1）每次操作最多产生一个空栈。
（2）总共的删除数 <= 总共产生的空栈数 <= n.

2、如果当前操作使一个栈由 满 -> 不满, 则该 index 进堆。 总共耗时: O(nlog(n))。

### (2) push 找到第一个未满栈
1、如果堆中没有元素，说明直到最后一个非空栈，栈都是满的。因此在最后一个非空栈（也是满的）之后“添加”一个新栈。若新栈没有满，在堆中插入新栈的 index.

2、如果有元素，则在该栈上插入即可。

3、push 总共耗时: O(n).

### 代码
548ms 100%
```cpp
class DinnerPlates {
    int cap;
    vector<int> data;
    vector<int> sz; // 各个栈的元素数
    vector<int> nfill; // 最小堆
public:
    void hp_up_min(vector<int>& hp) // 最小堆 小值上浮
    {
        for(int idx = hp.size() - 1; hp[idx] < hp[idx / 2]; idx /= 2)
        { int tmp = hp[idx]; hp[idx] = hp[idx / 2]; hp[idx / 2] = tmp; }
    }
    void hp_down_min(vector<int>& hp, int idx) // 最小堆 大值下沉
    {
        if(idx >= hp.size()) return;
        int l = (idx << 1), r = (idx << 1) + 1;
        int vl = (l >= hp.size()) ? INT_MAX : hp[l];
        int vr = (r >= hp.size()) ? INT_MAX : hp[r];
        int m = min(vl,vr), n = (vl <= vr)? l : r;
        if(hp[idx] > m)
        {
            hp[n] = hp[idx];
            hp[idx] = m;
            hp_down_min(hp,n);
        }
    }
    void hp_push_nfill(int val)
    {
        nfill.push_back(val);
        hp_up_min(nfill);
    }
    void hp_pop_nfill()
    {
        if(nfill.size() == 1) return;
        nfill[1] = nfill.back();
        nfill.pop_back();
        hp_down_min(nfill, 1);
    }
    int hp_top_nfill()
    {
        if(nfill.size() == 1) return -1;
        return nfill[1];
    }

    DinnerPlates(int capacity) {
        cap = capacity;
        nfill.push_back(0);
    }
    
    void push(int val) {
        int index = hp_top_nfill();
        if(index == -1)
        {
            index = sz.size();
            hp_push_nfill(index);
        }
        if(index == sz.size()) sz.push_back(0);
        int didx = index*cap + (sz[index]++);
        if(didx == data.size()) data.push_back(val);
        else data[didx] = val;
        if(sz[index] == cap) hp_pop_nfill();
    }
    
    int pop() {
        return popAtStack(sz.size() - 1);
    }
    
    int popAtStack(int index) {
        if(index >= sz.size()) return -1;
        if(sz[index] == cap) hp_push_nfill(index);
        if(sz[index] == 0) return -1;
        int ret = data[index*cap + (--sz[index])];
        while(sz.size() > 0 && sz.back() == 0) sz.pop_back();
        return ret;
    }
};
```



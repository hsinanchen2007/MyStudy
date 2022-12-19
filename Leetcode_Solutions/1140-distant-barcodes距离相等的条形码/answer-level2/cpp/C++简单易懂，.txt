在题目必定有解的前提下

比较好理解的方法是将所有的标签都分类，按从数量多少排降序

然后把数量最多的先放在ret的奇数位，再放数量第二多的再奇数位，在奇数位填满后，填充偶数位

这就可以直接上代码了：

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> valmap;
    priority_queue<pair<int, int>> p; //pair<num, value>
    int src_len = barcodes.size();
    vector<int> ret(src_len, 0);

    for (int i = 0; i < src_len; ++i)
    {
        if (valmap.find(barcodes[i])!=valmap.end())
            valmap[barcodes[i]]++;
        else
            valmap[barcodes[i]] = 1;
    }
    auto iter = valmap.begin();
    while (iter != valmap.end())
    {
        p.push({ iter->second, iter->first });
        iter++;
    }
    int i = 0;
    while (!p.empty())
    {
        //推一个，删一个
        auto pt = p.top();
        p.pop();
        for (int j = 0; j < pt.first; ++j) {
            ret[i] = pt.second;
            i = (i + 2 >= src_len) ? 1 : i + 2;
        }
    }
    return ret;
    }
};
可是这样可能会耗时间在排序上面，也不知道是不是因为用了 priority_queue（优先队列），该队列可以在定义的时候，声明是降序还是升序，默认降序）；主要我看其他的操作应该不太占时间，问题应该出现在这里，LeetCode上面该代码耗时300ms

第二种方法
这个比较传统，利用两次双指针，前面来一次，后面来一次。这个比较好理解，算是暴力破解了

为什么要来两次呢，为了避免在最后两个位置出现一样的情况出现

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    if (barcodes.size() <= 2)
        return barcodes;
    int src_len = barcodes.size();

    int i = 1, j = 0;
    for (i; i < src_len; )
    {
        if (barcodes[i] == barcodes[j])
        {
            i++;
        }
        else
        {
            int tmp = barcodes[j + 1];
            barcodes[j + 1] = barcodes[i];
            barcodes[i] = tmp;
            j++;
            i = j+1;
        }
    }

    i = src_len - 2;
    j = src_len - 1;
    for (i; i >= 0;)
    {
        if (barcodes[i] == barcodes[j]) 
            i--;
        else
        {
            int imp = barcodes[j - 1];
            barcodes[j - 1] = barcodes[i];
            barcodes[i] = imp;
            j--;
            i = j - 1;
        }
    }
    return barcodes;
    }
};
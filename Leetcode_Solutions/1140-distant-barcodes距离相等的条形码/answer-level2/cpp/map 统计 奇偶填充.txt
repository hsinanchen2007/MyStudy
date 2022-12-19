由 ：此题保证存在答案 得出 相同元素出现次数最多 不会大于数组大小的一半 maxCount <= barcodes[i].size() / 2;

首先把用map 统计 各元素出现的次数。

然后从奇数位开始填充，填满后填偶数位。

考虑到一种特殊情况
当填充完奇数位时，当时的元素count数量还没用完，它就会去填充偶数位，这样就不满足题目要求了
所以需要先找到元素count最大的先填充奇数位
```
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
       map<int,int> tmpCount;
        
        for(int i = 0; i < barcodes.size(); i++)
        {
            tmpCount[barcodes[i]]++;
        }
       
        int danIndex = 0;
        int suanIndex = 1;
        auto itmax = tmpCount.begin();

        for(auto it = itmax; it != tmpCount.end(); it++)             //找出最多的
        {
            if(it->second > itmax->second)
            {
                itmax = it;
            }
        }
        
        while(danIndex < barcodes.size() && itmax->second > 0) //先把元素最多的填充
                barcodes[danIndex] = itmax->first;
                danIndex += 2;
                itmax->second--;
            }
        
        for( auto it = tmpCount.begin(); it != tmpCount.end(); it++)
        {
            while(danIndex < barcodes.size() && it->second > 0)    //奇数没填完继续
            {
                barcodes[danIndex] = it->first;
                danIndex += 2;
                it->second--;
            }
            
             while(suanIndex < barcodes.size() && it->second > 0)  //然后偶数
            {
                barcodes[suanIndex] = it->first;
                suanIndex += 2;
                it->second--;
            }
        }
        
        return barcodes;
    }
};
```


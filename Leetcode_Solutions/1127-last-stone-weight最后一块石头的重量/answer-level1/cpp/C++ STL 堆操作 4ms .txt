#### 最大堆，剩余石块多于1时，总可以粉碎，出堆最大的两颗石头，如果重量不同入堆重量的差
```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //特判
        if(stones.empty()) return 0;
        int num = stones.size();
        if(num==1) return stones.at(0);
        make_heap(stones.begin(), stones.end());
        while(num>1)
        {
            int weight1 = stones.front();
            pop_heap(stones.begin(), stones.begin()+num);
            int weight2 = stones.front();
            pop_heap(stones.begin(), stones.begin()+num-1);
            num-=2;
            if(weight1!=weight2)
            {
                if(stones.size()<=num) stones.push_back(abs(weight1-weight2));
                else stones.at(num) = abs(weight1-weight2);
                push_heap(stones.begin(), stones.begin()+num+1);
                num++;
            }
        }
        if(num==0) return 0;
        else return stones.at(0);
    }
};
```

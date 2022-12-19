### 解题思路
容器的办法缺点速度慢优点好写，手码方法更好的理解每个块的走向，锻炼自己的思维。
### 代码
先进行排序，进入循环，相等的值就continue，顺便把left标记一下，left回到第一个相等的地方。如果是顺子，num计数器就自增1，并且把ans赋值，hand[i]变成-1.
当遍历一个下标他不是顺序的并且没有遍历过就return false;当计数器等于W的时候，先判断left是不是-1，如果不等于-1回到left的下标，并且重置ans的值
```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()==0||W==0)return false;
        if(hand.size()%W!=0)return false;
        if(W==1)return true;
        sort(hand.begin(),hand.end());
        int left=-1;
        int num=1;
        int ans=hand[0];
        for(size_t i=1;i<hand.size();++i){
            if(ans==(hand[i]-1)){
                ans=hand[i];
                ++num;
                hand[i]=-1;
            }
            else if(ans==hand[i]){
                if(left==-1){
                    left=i-1;//i-1是因为，-1在continue又+1，相当于没有变化
                }
                continue;
            }
            else if(hand[i]!=-1&&ans!=(hand[i]-1))return false;
            if(num==W){
                if(left!=-1)i=left;
                left=-1;
                num=1;
                if(i+1!=hand.size()){
                    ans=hand[i+1];
                    hand[i + 1] = -1;
                }
            }
        }
        if(hand.back()!=-1)return false;//防止{1,1,2,2,3,3}这样的例子，因为是for必

        return true;
        
    }
};
第二种方法，map容器
map容器就没什么好讲的了，一搜就是一大把

bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() == 0 || W == 0)return false;
        if (hand.size() % W != 0)return false;
        if (W == 1)return true;
        map<int, int>m;
        for (size_t i = 0; i < hand.size(); ++i) {
            ++m[hand[i]];
        }

        while (!m.empty()) {
            int ans=m.begin()->first;
            --m[ans];
            if(m[ans]==0)m.erase(ans);
            for(size_t i=1;i<W;++i){
                auto it=m.find(ans+i);
                if(it!=m.end()){
                    --m[it->first];
                    if(m[it->first]==0)m.erase(it->first);
                }
                else return false;
            }
        }

	return true;

```



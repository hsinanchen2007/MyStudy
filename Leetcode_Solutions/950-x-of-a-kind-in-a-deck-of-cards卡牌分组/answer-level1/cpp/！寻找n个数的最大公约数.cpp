### 解题思路
一下代码效率极低，执行用时仅击败15.70%；
但是易于理解，思路在注释中；
题解中的效率更高，在遍历map时直接寻找最大公约数。

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        //使用mp统计所有牌出现的数量，然后找最小的，看其他的能否分成最小的因子的倍数
        if (deck.size()<2) return false;
        map<int, int> mp;
        for (int i=0; i<deck.size();i++) mp[deck[i]]++;
        int low=INT_MAX;
        for(map<int, int> :: iterator it=mp.begin(); it!=mp.end(); it++){//找最小的数
            if (it->second < low){
                low=it->second;
                if (low==1) return false;
            }
        }
        int yz=2;
        vector<int> yinzi;
        for (; yz <= low; yz++) if (low % yz ==0) yinzi.push_back(yz);//大于等于3的所有因子
        for(int i=0; i<yinzi.size(); i++){//对所有因子进行实验
            map<int, int> :: iterator it=mp.begin();
            for(; it!=mp.end(); it++){
                if (it->second % yinzi[i] != 0) break;
            }
            if (it==mp.end()) return true;//找到了合适的因子
        }
        return false;
    }
};
```
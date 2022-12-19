
// 核心问题就是: 
    // 不同卡牌个数  拥有相同的因数（>= 2）==》ture 否则false

那么有连个办法来快速的比较：
方法一：
    // 第一个数字的因数可以作为备选的x的集合
    // 集合种的每个数备选 bx， 不同卡牌个数 y
    // 如果bx是 bx是y的因数 则保留，否则去掉
    // 最后集合还有数就是true否则false
方法二：即官方题解的二
求所有数之间的最大公约数；
x1,x2的最大公约数gcd
之后，每个数和gcd产生新的gcd
gcd = __gcd(gcd, xi);



``` 
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
         unordered_map <int, int> hash;
        vector<int>::iterator p = deck.begin();

        if (deck.size() <= 1)
            return false;
        // 每种卡牌的数量
        while (p != deck.end()){
            auto it = hash.find(*p);
            if (it == hash.end()){
                hash.insert({*p, 1});
            }
            else{
                it->second += 1;
            }
            p ++;
        }

        // 备选集合
        auto ph = hash.begin();
        int num = ph->second;
        ph ++;

        vector<int> bx;
        int x = 2;
        while (x <= num/2){
            if (num%x == 0){
                bx.push_back(x);
            }
              
            x ++;
        }
        bx.push_back(num);                // 如果有一种卡牌只有一张，那必然是false
                                          // 以上不会把 1放进备选，除非是 这个数本身是1
        if (num == 1)           
            return false;
            
        // 测试
        while (ph != hash.end()){
            num = ph->second;
            if (num == 1)           // 如果有一种卡牌只有一张，那必然是false
                return false;
            vector<int>::iterator pbx = bx.begin();
            while (pbx!= bx.end()){
                if (num % *pbx != 0){
                    pbx = bx.erase(pbx);
                }
                else
                    pbx ++;
            }
            ph ++;
        }

        return bx.size() > 0;
    }
};
```
### 解题思路
此处撰写解题思路
借用一位大佬的思路；
为了避免暴力求出所有数的个数的最大公约数；
可以先将10000以内的素数筛选出来。
原因如下：
    首先需要找出数组内出现次数最少的数的次数记录下来，暂且计做MIN；
    然后就从2到MIN之间去找一个能被所有次数所整除的素数。
    对于一个大于2的合数一定能找出一个素数p，p < x 使得 x % p == 0;
判断时:可以优化的点，
若deck.size() <= 1,return false;
若deck.size() % p != 0即可直接进入下一循环（因为数组不能被等分）
若p > MIN 直接返回false因为找不到一个能被所有数整除的素数
若p能被所有次数整除，及时返回true;
下面放上原作者的链接，有图解，建议看下
作者：Time-Limit
链接：https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/solution/tu-jie-su-shu-shai-c-by-time-limit/

### 代码

```cpp
class Solution {
public:
    bool v[10001] = {0};
    vector<int>primes;
    bool hasGroupsSizeX(vector<int>& deck) {
     for(int i = 2; i < 10000; i++){
            if(v[i] == true){
                continue;
            }
            primes.push_back(i);
            for(int j = i + i; j < 10000; j = j + i){
                 v[j] = true;
          }
     }
     unordered_map<int,int> cnt;
        for(auto v: deck){
             cnt[v]++;
        }
        auto minIter = cnt.begin();
        for(auto it = cnt.begin(); it != cnt.end(); it++){
            if(it->second < minIter->second){
                minIter = it;
            }
        }
        if(minIter->second <= 1){
            return false;
        }
        for(auto v : primes){
            if(deck.size() % v){
                continue;
            }
            if(v > minIter->second){
                break;
            }
            bool flag = true;
            for(auto it = cnt.cbegin(); flag && it != cnt.cend(); it++){
                if(it -> second % v){
                    flag = false;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};

    

 for(auto v : deck) {
            cnt[v]++;
        }
        auto minIter = cnt.begin();
        for(auto it = cnt.begin(); it != cnt.end(); it++) {
            if(it->second < minIter->second) {
                minIter = it;
            }
        }
        if(minIter->second <= 1) {
            return false;
        }
        for(auto v : primes) {
            if(deck.size() % v) {
                continue;
            }
            if(v > minIter->second) {
                break;
            }
            bool flag = true;
            for(auto it = cnt.cbegin(); flag && it != cnt.cend(); ++it) {
                if(it->second % v) {
                    flag = false;
                }
            }
            if(flag) {
                return true;
            }
        }
        return false;
    }
};


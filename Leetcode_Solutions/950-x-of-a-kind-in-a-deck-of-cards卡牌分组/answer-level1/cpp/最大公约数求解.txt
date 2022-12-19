### 解题思路
每日打卡，算法学习刚入门，比较难受，所有的错误都遇到了一遍，希望我的错误能够帮助到同样刚入门的朋友
一开始看到这个题目，首先想到的是，建立一个哈希表，如果遇到了不相同的键值则返回false,而且用了两个数组来防止重复访问，然后瞬间打脸，比如[1,1,2,2,2,2]（键值不同）,
它可以分成[1,1],[2,2],[2,2]，发现这个错误后，我又觉得可以判断键值是否都为奇数或者偶数（当时理所当然的认为一奇一偶就不行），然后再次打脸，
比如[1,1,1,2,2,2,2,2,2] 它可以分成，[1,1,1],[2,2,2],[2,2,2]（一奇一偶），经过这个错误我认为，是否每个键值只要成倍数就返回true，如果有一个不成倍数，就返回false,结果第三次打脸，比如说[1,1,1,1,2,2,2,2,2,2]，它可以分成[1,1],[1,1],[2,2],[2,2],[2,2]（4和6不成倍数）,直到最后一次思考，发现可以通过判断它们的最大公约数来确定它们能不能分出来，只要任意两个键值的最大公约数是1，证明无法分出，则返回false,这次终于成功了，不过时间复杂度和空间复杂度还是被完虐，大佬的思维还是太具技巧性了（膜拜）。

希望思路相近的朋友能够指点一下代码的不足，空间和时间浪费的地方怎么优化，谢谢~

### 代码

```cpp
class Solution {
public:
    int gcd(int a, int b)
           {
               if(b == 0) return a;
               else return gcd(b,a%b);
           }     
    bool hasGroupsSizeX(vector<int>& deck) {       
           if(deck.size()==0||deck.size()==1)return false;
           unordered_map<int,int> hashmap;   
           int ans[10007] = {0};    //ans中不等于0的数就是哈希表中键值大于0的数
           bool appear_cnt[10007] = {false};//防止重复存相同的值到ans中，
           int num = 0;//num是为了之后的循环不循环10000次，只用循环num次.
           for(int i : deck)
           {
               ++hashmap[i];
               if(!appear_cnt[i])
               {
                    ans[num++] = i;
                    appear_cnt[i] = true;
               }
           }           
           
           for(int i = 0 ; i < num - 1 ; i++)
           {
              int res = gcd(hashmap[ans[i]],hashmap[ans[i+1]]);
              if(res == 1)return false;
           }
           
         return true;
    }
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Trie{
public:
    int value;
    vector<Trie*> child;
    Trie():value(-1), child(2, nullptr){}
    ~Trie(){
        for(Trie *chi:child){
            if(chi){delete chi;}
        }
    }
};
class Solution {
public:
    Trie *root = new Trie();
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        //将每个数的32位逐一加入字典树 最后存储这条路径所代表的值
        //当前位为0 则child[0] 申请指针 反之 相反
        for(auto num:nums){
            Trie *nowTrie = root;
            for(int i = 31; i >= 0; i--){
                int childIndex = num >> i & 1;
                if(!nowTrie->child[childIndex]){
                    nowTrie->child[childIndex] = new Trie();
                }
                nowTrie = nowTrie->child[childIndex];
            }
            nowTrie->value = num;
        }
        //逐一访问每个数的32位 因为最坏情况就是访问到自己 不至于出现空Trie指针
        //贪心：从高位开始访问 若当前位为1 则看原始有没有本位为0的（即child[0]指针不为空） 若有 优先走这条路 反之相反
        //贪心策略 即先走与本位异或后为1的路
        //每次循环更新异或结果
        for(auto num:nums){
            Trie *nowTrie = root;
            for(int i = 31; i >= 0; i--){
                int childIndex = num >> i & 1;
                if(childIndex == 0){
                    if(nowTrie->child[1]){
                        nowTrie = nowTrie->child[1];
                    }else{
                        nowTrie = nowTrie->child[0];
                    }
                }else{
                    if(nowTrie->child[0]){
                        nowTrie = nowTrie->child[0];
                    }else{
                        nowTrie = nowTrie->child[1];
                    }
                }
            }
            int temp = nowTrie->value;
            res = max(res, temp ^ num);
        }
        return res;
    }
};
```
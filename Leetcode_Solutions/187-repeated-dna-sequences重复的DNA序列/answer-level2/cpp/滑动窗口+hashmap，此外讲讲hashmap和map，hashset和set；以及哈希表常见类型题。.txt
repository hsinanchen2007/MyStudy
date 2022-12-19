重点在于滑动窗口加hashmap，而位运算提供了一种如何将10个字母的字符串“映射”（独一无二的）为数值以便作为索引。（实际上不转化也行，不过效率低很多）
```
//滑动窗口+位运算+哈希
//复杂度: O(s.length)，如果是那种粗暴的做法，复杂度应该是n方
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> map;
        vector<string> ret;
        unsigned int key = 0;
        for(int i = 0;i<s.length();++i){
            key = ((key<<3)|(s[i] & 0x7)) & 0x3FFFFFFF;
            if(i<9)
                continue;
            if(map.find(key) == map.end())
                map[key] = 1;
            else if(map[key] == 1){
                ret.push_back(s.substr(i-9,10));
                map[key]++;
            }
        }
        return ret;
    }
};
```
关于哈希表的题。诀窍在于数组（也可不是数组）中的i不是简单的索引了，往往赋予了更多意义。
1. 常直接用数组表示所有可能的元素，然后计数\flag；再就是像hashmap这样，不必生成所有可能，只是插入已出现的情况（**另类的flag数组**）。有的时候索引的获得需要费点力气，比如这道题或者两数之和的那道题。使得本来不同位置或者内容不同的东西，能够转化成同一个索引得以碰撞在一起，进行计数orflag。
2. 还有的题，就只是利用hash或者set访问快的同时又不用预分配那么大的空间去包含所有可能性。https://leetcode-cn.com/problems/contains-duplicate-ii/另一种类型的滑动窗口。索引并不是很重要。当成集合用。还有Single Number也是这种类型
——————————————————————————————————————————————————
map的底层是红黑树，查找插入删除均为对数复杂度，set同理。key为有序排列。
unorderded_map中key为无序排列，底层实现为hash table，理想情况查找复杂度为常数，消耗内存较多。此处的unordered_map其实就是hash_map。unordered_set同理。

至于为何map的key有序是因为红黑树是二叉排序树，而hashmap的key无序是因为按buckets遍历的。

![image.png](https://pic.leetcode-cn.com/20f74782099ac0f08f8a25d0f201ccaea17861aeeafe08da597178fe326f74a8-image.png)
[图源](https://plu.one/%E5%90%8E%E7%AB%AF%E5%BC%80%E5%8F%91/2018/08/09/why-hashmap-unordered/)



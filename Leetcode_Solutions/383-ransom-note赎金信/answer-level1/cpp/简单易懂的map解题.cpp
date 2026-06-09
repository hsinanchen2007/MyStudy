### 解题思路
1.读题可知即为判断一个字符串能否由另一个字符串组成
2.首先遍历字符串magazine，将每个元素以及出现次数保存进：map<元素，出现次数>
3.遍历ransomNote，判断map中对应的值是否大于0，大于0即存在，将值减1，循环结束返回true，若不大于0则直接返回false.
4.这个思路可以解349两个数组的交集，350. 两个数组的交集 II等问题
### 代码

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ump;
        for(int i=0;i<magazine.size();++i){
            ++ump[magazine[i]];
        }
        for(int j=0;j<ransomNote.size();++j){
            if(ump[ransomNote[j]] > 0){
                --ump[ransomNote[j]];
            }
            else{
                return false;
            }
        }
        return true;
    }
};


```
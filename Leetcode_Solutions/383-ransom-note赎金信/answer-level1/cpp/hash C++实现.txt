> 执行用时 : 12 ms, 在Ransom Note的C++提交中击败了100.00% 的用户

> 内存消耗 : 10.9 MB, 在Ransom Note的C++提交中击败了82.67% 的用户

1. 建立一个包含26个小写字母的表hash，然后将各个字母的数量映射到hash中。
2. 对magazine进行循环，将对应的字母-1，直到出现负数，即条件不满足，返回false。
3. 满足上述循环即可返回true。

时间复杂度为O(n)

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine){
        int hash[26] = {0};
        for(int i = 0;magazine[i];++i){
            hash[magazine[i]-'a'] += 1;
        }
        for(int i = 0;ransomNote[i];++i){
            hash[ransomNote[i]-'a'] -= 1;
            if(hash[ransomNote[i] - 'a'] < 0)return false;
        }
        return true;
    }
};
```

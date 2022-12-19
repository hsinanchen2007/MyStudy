这道题的输入都是小写字母，因此开一个大小为26的整型数组来存每个字母的数量即可。
cnt[0] -> 'a'
cnt[1] -> 'b'
……
cnt[24] -> 'y'
cnt[25] -> 'z'

1 遍历“杂志”字符串，将每个字母对应在数组中的元素值+1
2 遍历“赎金信”字符串，将每个字母对应在数组中的元素值-1
若数组中出现某个元素值<0（该字母数量不足），即无法构成赎金信，返回false
3 “赎金信”字符串遍历结束仍未返回false时，返回true
```
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};        
        for(int i = 0; i < magazine.length(); i++) 
            cnt[magazine[i]-'a']++;                         
        for(int i = 0; i < ransomNote.length(); i++) 
            if(--cnt[ransomNote[i]-'a'] < 0) return false;   
        return true;
    }
};
```
时间复杂度：O(n+m)
空间复杂度：O(1)
### 解题思路
本题假设了只含有小写字母，故使用**数组**进行存储数据

- 首先判断两个字符串长度是否相等，不等则直接返回`false`

- 然后定义一个**计数数组`cnt`**，将`s`中遍历到的每个字母的**频率 ++**，而将`t`中对应字母的**频率 --**

- 这样做的目的会清楚的判断两字符串中是否包含相同元素，若**元素频率不相同**则返回`false`，否则返回`true`

### 代码

```java []
class Solution {
    public boolean isAnagram(String s, String t) {
        if ( s.length() != t.length() ) {
             return false;
        }
        
        // 题目假设只包含小写字母，估定义一个长度 26 的数组即可
        int[] cnt = new int[26];        
        for(int i = 0; i < s.length(); i++){
            // 扫描字符串 s 中元素个数 ++
            cnt[s.charAt(i) - 'a']++;
            // 扫描字符串 t 中对应的元素个数 --
            cnt[t.charAt(i) - 'a']--;
        }
        
        // 遍历计数数组 cnt 计算 s 字母的频率，同时用 t 减少对应字母的频率
        for(int c : cnt){
            // 若 s 和 t 中对应字母频率相同，则剩余的计数为 0，否则不为 0 
            if(c != 0){
                return false;
            }
        }
        return true;
    }
}
```
借助一个辅助空的数组cnt 
利用ascii表中字母对应的数字，修改数组cnt[对应字母的数字] = 0 的值
第二步再次遍历数组 cnt[对应字母的数字] = ? 当？= 1时，返回。
```java []
class Solution {
    public int firstUniqChar(String s) {
        int[] cnt = new int[256];     
        char[] c = s.toCharArray();
        
        for(int i=0; i < c.length; i++){
            char str = c[i];
            cnt[str]++;
        }
        //第二步
        for (int i = 0; i< s.length(); i++){
            if (cnt[s.charAt(i)] == 1){
                return i;
            }
        }
        return -1;
    }
}

```
```python []
'''先遍历一次字符串的每个字符，并用hash记录每个字符对应的下标，若出现重复字符，则把下标设置为字符串长度。
遍历完字符之后，取hash实值中的最小值，若最小值等于字符串长度，表明字符串中全是重复字符，返回-1;
否则最小值恰好是第一个单独出现的字符对应下标。'''
class Solution:
    def firstUniqChar(self, s: str) -> int:
        if s is None or s == "":
            return -1
        if len(s) == 0:
            return 0
        
        record = {}
        for i, c in enumerate(s):
            if c not in record:
                record[c] = i
            else:
                record[c] = len(s)
                
        index = min(record.values())
        if index == len(s):
            return -1
        return index
```
思考这个题数组和哈希表哪个方法占用的内存小？


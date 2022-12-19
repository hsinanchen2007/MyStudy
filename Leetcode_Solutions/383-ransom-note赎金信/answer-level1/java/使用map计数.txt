思路：
1.使用map记录ransomNote中每个元素出现的次数
2.遍历manazine，出现map中的元素时，其对应的键值减一
3.map中键值存在有大于0的则返回false，否则返回true
时间复杂度：O(n),空间复杂度O(n)

```
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int rLen = ransomNote.length();
        int mLen = magazine.length();
        if(rLen > mLen)
            return false;
        Map<Character, Integer> m = new HashMap();//计算每个元素的出现次数

        //统计ransomNote每个元素出现的次数
        for (int i = 0; i < rLen; i++) {
            char x = ransomNote.charAt(i);
            if (m.get(x) == null)  
                m.put(x, 1);
            else
                m.put(x,m.get(x)+1);
        }

        for(int j = 0;j < mLen;j ++){
            char x = magazine.charAt(j);
            if (m.get(x) != null)  
                m.put(x,m.get(x)-1);                
        }

        for (int i = 0; i < rLen; i++) {
            char x = ransomNote.charAt(i);
            if (m.get(x) > 0)
                return false;
        }
        return true;
    }
}
```

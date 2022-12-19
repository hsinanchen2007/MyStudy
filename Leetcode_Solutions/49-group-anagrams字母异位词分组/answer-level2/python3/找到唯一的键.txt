## 思路:

这道题关键在于,如何找到可以唯一标识具有相同字母并且个数也一样的**键**:

思路一:单词按字典顺序排序

思路二:用素数.

思路三: 按字母个数(大家自行写代码)

------



## 代码:

思路一

```python [1]
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        from collections import defaultdict
        lookup = defaultdict(list)
        for s in strs:
            lookup["".join(sorted(s))].append(s)
        return list(lookup.values())
```

```java [1]
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs == null || strs.length ==0)  return new ArrayList<List<String>>();
        Map<String, List<String>> map= new HashMap<>();
        for (String str : strs) {
            char[] tmp = str.toCharArray();
            Arrays.sort(tmp);
            String keyStr = String.valueOf(tmp);
            if (! map.containsKey(keyStr)) map.put(keyStr,new ArrayList<String>());
            map.get(keyStr).add(str);
        }
        return new ArrayList<>(map.values());
        
    }
}
```

思路二

```python [2]
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        from collections import defaultdict
        prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103]
        lookup = defaultdict(list)
        for _str in strs:
            key_val = 1
            for s in _str:
                key_val *= prime[ord(s) - 97]
            lookup[key_val].append(_str)
        return list(lookup.values())
```

```java [2]
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int[] prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        Map<Integer,List<String>> map = new HashMap<>();
        for (String str : strs) {
            int key = 1;
            for(char c : str.toCharArray()){
                key *= prime[c - 'a'];
            }
            if (!map.containsKey(key)) map.put(key, new ArrayList<String>());
            map.get(key).add(str);
        }
        return new ArrayList<>(map.values());
    }
}
```


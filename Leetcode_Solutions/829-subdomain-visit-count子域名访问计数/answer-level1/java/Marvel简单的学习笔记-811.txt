### 解题思路
利用字符串的split()方法，将字符串分割为访问次数和域名，再将域名分割为各级域名，然后对每一级域名进行处理，分别添加进哈希表。
哈希表使用HashMap，记录各域名到其访问次数的映射。
最后遍历哈希表输出结果。
详见代码。

### 代码

```java
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        for(String s : cpdomains)
        {
            String[] s1 = s.split("\\s+");
            String[] s2 = s1[1].split("\\.");
            String domain = "";
            for(int i = s2.length - 1; i >= 0; i--)
            {
                if(i < s2.length-1) domain = "." + domain;
                domain = s2[i] + domain;
                int times = map.getOrDefault(domain, 0) + Integer.parseInt(s1[0]);
                map.put(domain, times);
            }
        }
        List<String> list = new LinkedList<String>();
        for(Map.Entry<String, Integer> entry : map.entrySet())
            list.add(entry.getValue() + " " + entry.getKey());
        return list;
    }
}
```
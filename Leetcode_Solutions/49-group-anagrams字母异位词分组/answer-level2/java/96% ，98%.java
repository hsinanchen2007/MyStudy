### 解题思路
![微信图片_20200206165052.png](https://pic.leetcode-cn.com/83caa634683893a6c62728b22ac6d6983f2e00ae0ff330bf83efa242a00d5867-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200206165052.png)

1.对每个字符串排序
2.跟map中对比，一样就把原字符串加入到value中，不一样就建一个新的
3.把map中的value都加入结果。

### 代码

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> map=new HashMap<>();
        for (String str:strs){
            char [] s= str.toCharArray();
            Arrays.sort(s);
            String find=new String(s);
            if (map.containsKey(find)){
                List<String> arr=map.get(find);
                arr.add(str);
                map.put(find,arr);
            }
            else{
                List<String> arr=new ArrayList<>();
                arr.add(str);
                map.put(find,arr);
            }
        }
        return new ArrayList<>(map.values());
    }
}
```
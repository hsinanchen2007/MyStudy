先连接两个字符，存在hashmap中, 然后将选中的存在arraylist中，再转为string[]

![image.png](https://pic.leetcode-cn.com/3e577dbe53bb4c7e1f2d61d0fe0db6c5753cc9ec97c4eb067d9a77bc4ab2f21a-image.png)

```javascript []
class Solution {
    public String[] uncommonFromSentences(String A, String B) {

        ArrayList<String> list = new ArrayList<>();
        HashMap<String, Boolean> map = new HashMap<>();
        String[] C = (A + " " + B).split(" ");
        for (String string: C)
            if(map.containsKey(string))
                map.put(string, true);
            else
                map.put(string, false);
        
        for (Map.Entry<String, Boolean> entry: map.entrySet())
            if (entry.getValue() == false)
                list.add(entry.getKey());
        return list.toArray(new String[list.size()]);
    }
}
```


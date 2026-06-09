### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        //哈希集合法
        Map<Integer,List<Integer>> map=new HashMap<>();
        List<List<Integer>> res=new ArrayList<>();
        for(int i=0;i<groupSizes.length;i++)
        {
            if(!map.containsKey(groupSizes[i]))
                map.put(groupSizes[i],new ArrayList());
            List<Integer> list=map.get(groupSizes[i]);
            list.add(i);
            if(list.size()==groupSizes[i])
            {
                res.add(new ArrayList(list));
                list.clear();
            }
        }
        return res;
    }
}
```
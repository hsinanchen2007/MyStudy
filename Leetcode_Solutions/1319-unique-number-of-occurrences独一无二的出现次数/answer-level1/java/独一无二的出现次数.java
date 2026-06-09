### 解题思路
    首先先将数组中所有的元素填入哈希表中，每填入一个相同的元素，key对应的value值加1。
然后构建一个哈希集合，遍历哈希表中的每一个value值，如果在集合中没出现过，则放入集合中。否则，则返回false，
即出现次数不是独一无二的。

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map <Integer,Integer> map= new HashMap<Integer, Integer>();
        for(int i:arr)
        {
           map.put(i,map.getOrDefault(i, 0)+1);
        }
        Set <Integer> set = new HashSet<Integer>();
		//set统计value是否重复出现
		for (int val : map.values())
        {
            if(set.contains(val))
                return false;
            else
                set.add(val);
		}
		return true;

    }
}
```
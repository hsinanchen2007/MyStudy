### 解题思路
使用一个哈希表记录list1[]中的每个单词及其对应索引，使用一个变量记录当前最小的索引和，使用一个list存放索引和最小的共同喜爱的餐厅。
之后遍历list2[]中的每个单词，若哈希表中存在，意味着有共同喜好，则计算索引，若小于当前最小索引，则更新最小索引，清空output，放入此共同喜爱的单词；若等于当前最小索引，则将该单词添加进output。遍历完成后输出output为String[]。

时间复杂度：O(n)。
空间复杂度：O(n)。最坏情况下，两个数组元素完全相同，且其中一个为另一个的逆序，则所有单词都是索引和最小的共同喜好。

### 代码

```java
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        int index = 2000;
        List<String> output = new ArrayList<String>();
        for(int i = 0; i < list1.length; i++)
            map.put(list1[i], i);
        for(int i = 0; i < list2.length; i++)
        {
            String s = list2[i];
            if(map.containsKey(s))
            {
                int j = map.get(s);
                if(i + j < index)
                {
                    output.clear();
                    output.add(s);
                    index = i + j;
                }
                else if(i + j == index)
                    output.add(s);
            }
        }
        return output.toArray(new String[output.size()]);
    }
}
```
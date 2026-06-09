### 解题思路
先把字符串text转换为Character类型数组，然后foreach循环遍历把每一个字母都放入到map集合计算其数量
然后求出balloons中单个字母数量最少的字母，即为题目所求
![image.png](https://pic.leetcode-cn.com/23f77b5316a2d6f5bff84b9af13fabdd99e9ee7e90e35d245873a0911b8d50c3-image.png)

### 代码

```java
class Solution {
    public int maxNumberOfBalloons(String text) {
         HashMap<Character, Integer> map = new HashMap<>();
        for (Character c :text.toCharArray()) {
            if (map.containsKey(c)){
                map.put(c, map.get(c)+1);
            }else {
                map.put(c, 1);
            }
        }
        ArrayList<Integer> list = new ArrayList<>();

        list.add(map.get('b')==null?0:map.get('b'));
        list.add(map.get('a')==null?0:map.get('a'));
        list.add(map.get('l')==null?0:map.get('l')/2);
        list.add(map.get('o')==null?0:map.get('o')/2);
        list.add(map.get('n')==null?0:map.get('n'));
        list.sort((x,y)->x-y);
        return list.get(0);
    }
}
```
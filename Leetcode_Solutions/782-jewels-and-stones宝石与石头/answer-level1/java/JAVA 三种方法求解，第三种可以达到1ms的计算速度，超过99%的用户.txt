#### 解题思路：

1. 使用最简单的暴力求解，通过两个 for 循环嵌套对 J 和 S 进行遍历求解（PS：虽然理论上是最慢的，但不知道为啥很快。。。）
**复杂度分析：

时间复杂度：$O(n^2)$

空间复杂度：$O(1)$


```Java [-Java]
class Solution {
    public int numJewelsInStones(String J, String S) {
        int result = 0;
        for (int i = 0;i<J.length();i++)
        {
            String a = J.substring(i,i+1);
            for (int j = 0;j<S.length();j++){
                String b = S.substring(j,j+1);
                if(a.equals(b))
                    result++;
            }
        }
        J.substring(0,1);
        return result;
    }
}
```
2. 使用哈希表，使用 2 个独立的 for 循环，第一个对 S 中的各个字母重复的数量进行统计，并放入哈希表中。第二个 for 循环，对 J 中字母进行循环，与哈希表中的 KEY 值匹配，得到结果并进行叠加。
**复杂度分析：

时间复杂度：$O(n)$

空间复杂度：$O(n)$

```Java [-Java]
class Solution {
    public int numJewelsInStones(String J, String S) {
        int result = 0;
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for (int h = 0;h<S.length();h++)
        {
            String b = S.substring(h,h+1);
            if( map.get(b)==null){
                map.put(b, 1);
            }else{
                map.put(b, map.get(b)+1);
            }
        }
        for (int i = 0;i<J.length();i++)
        {
            String a = J.substring(i,i+1);
            if(map.containsKey(a))
                result=result+map.get(a);
        }
        return result;
}
}
```

3. 这里我们可以不使用 JAVA 自带哈希表，我们使用哈希表的一个思想，而使用数组来实现，以获得更快的速度，创建大小为 150 是一时兴起，只需要比所以的字母大就行了。

**复杂度分析：

时间复杂度：$O(n)$

空间复杂度：$O(n)**$

```
JAVA
class Solution {
    public int numJewelsInStones(String J, String S) {
        char[] Jc = J.toCharArray();
        char[] Sc = S.toCharArray();
        int result = 0;
        int[] indexMap = new int[150];
        for (int h = 0;h<S.length();h++)
        {
            indexMap[Sc[h]] = indexMap[Sc[h]]+1;
        }
        for (int i = 0;i<J.length();i++)
        {
            char a = Jc[i];
            result=result+indexMap[a];
        }
        return result;
}
}
```

**各位大佬看完了，欢迎交流点赞呀！！！**
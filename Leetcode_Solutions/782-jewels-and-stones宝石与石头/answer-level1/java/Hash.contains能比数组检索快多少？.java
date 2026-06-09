毕业之后再没写过这些都快忘光了。我记得哈希查key应该比数组检索快。但是需要先把数组填进hash表。这就要取决输入数据的类型了。

执行用时 : 4 ms, 在Jewels and Stones的Java提交中击败了70.66% 的用户
内存消耗 : 34.8 MB, 在Jewels and Stones的Java提交中击败了90.76% 的用户

```
class Solution {
   public int numJewelsInStones(String J, String S) {
        char[] types = J.toCharArray();
        char[] mine = S.toCharArray();
        HashMap<Character, ?> index = new HashMap<>();
        for (char t : types)
            index.put(t, null);
        int toReturn = 0;
        for (char m : mine)
            if (index.containsKey(m))
                toReturn++;
        return toReturn;
    }
}

```

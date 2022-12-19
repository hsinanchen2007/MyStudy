### 解题思路
此处撰写解题思路
### 代码
遍历一棵树， 输出从根结点到叶节点的路径， 是有深度优先搜索 + 回溯。 
```java
class Solution {
    public List<String> letterCombinations(String digits) {
        HashMap<Integer, String[]> dailPad = new HashMap<>();
        dailPad.put(2, new String[]{"a", "b", "c"});
        dailPad.put(3, new String[]{"d", "e", "f"});
        dailPad.put(4, new String[]{"g", "h", "i"});
        dailPad.put(5, new String[]{"j", "k", "l"});
        dailPad.put(6, new String[]{"m", "n", "o"});
        dailPad.put(7, new String[]{"p", "q", "r", "s"});
        dailPad.put(8, new String[]{"t", "u", "v"});
        dailPad.put(9, new String[]{"w", "x", "y", "z"});

        List<String> res = new ArrayList<>();
        if(digits == null || digits.length() == 0) return res;
        StringBuilder sb = new StringBuilder();
        DFS(sb, 0, digits, dailPad, res);
        return res;


    }
    public void DFS(StringBuilder sb, int start, String digits, HashMap<Integer, String[]> dailPad, List<String> res){
        if(sb.length() == digits.length()){
            res.add(sb.toString());
            return;
        }

        int key = digits.charAt(start)-'0';
        String[] temp = dailPad.get(key);

        for(int i=0; i<temp.length; i++){
            sb.append(temp[i]);
            DFS(sb,start+1,digits,dailPad, res);
            sb.setLength(sb.length() - 1);
        }
    }
}
```
### 解题思路
解题思路：
- 首先，拿一个示例来分析，例如“1211”。我们怎么得到它的下一个序列“111221”呢？很显然我们会从左向右数数。
- 然后，我们模拟数数的过程。假设有个指针在最左边，不断向右移动直到末尾。于是我们得到这样的口头表述：1个1，1个2，2个1。把这些数字连接起来就是111221。
- 综上所述，我们的工作就是要通过每个数字它的相同的、连续的数字个数。

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        List<String> list = new ArrayList<>();
        list.add("1");
        for(int i = 0; i < n - 1; i++){
            String target = list.get(i);
            String newSeq = getSeqString(target);
            list.add(newSeq);
            //System.out.println(list);
        }
        return list.get(list.size() - 1);
    }
    private String getSeqString(String target){
        int index = 0;
        StringBuilder sb = new StringBuilder();
        int size = target.length();
        while(index < size){
            int num = 1;
            while(index < size - 1 && target.charAt(index) == target.charAt(index + 1)){
                num++;
                index++;
            }
            sb.append(num);
            sb.append(target.charAt(index));
            index++;
        }
        return sb.toString();
    }
}
```
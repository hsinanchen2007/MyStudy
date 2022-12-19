### 解题思路
* 利用LinkedHashMap顺序存储的功能
* 纯属脑袋直接想出来的。

### 刷题进阶
* IDE用久了，Entry写成了EntrySet
* map的迭代需要用entrySet()函数来实现
* 不要直接使用Entry，要用Map.Entry来定义

### 代码

```java
class Solution {
    static class Node {
        Integer count;
        Integer index;
        public Node(Integer index,Integer count) {
            this.index = index;
            this.count = count;            
        }
        public Integer getCount() {
            return count;
        }
        public Integer getIndex() {
            return index;
        }
        public void increase() {
            this.count++;
        }
    }
    public int firstUniqChar(String s) {
        if( Objects.isNull(s) || s.isEmpty()) {
            return -1;
        }
        Map<Character,Node> letterCountMap = new LinkedHashMap<>();
        char[] chars = s.toCharArray();
        for(int i = 0; i < chars.length; i++) {
            char ch = chars[i];
            if(letterCountMap.containsKey(ch)){
                Node  node = letterCountMap.get(ch);
                node.increase();                                
            }else {
                Node newNode = new Node(i,1);
                letterCountMap.put(ch, newNode);
            }
        }
        Iterator<Map.Entry<Character,Node>> it = letterCountMap.entrySet().iterator();
        Map.Entry<Character,Node> entry = null;
        while(it.hasNext()) {
            entry = it.next();
            if (entry.getValue().getCount() == 1) {
                return entry.getValue().getIndex();
            }
        }
        return -1;
    }
}
```
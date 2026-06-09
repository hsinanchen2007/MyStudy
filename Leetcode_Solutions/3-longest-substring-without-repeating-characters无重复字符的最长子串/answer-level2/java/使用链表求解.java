### 解题思路
使用链表，满足条件链表尾部加数据，不满足条件链表头部删数据
时间复杂度O(n)

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        char[] arr = s.toCharArray();
        int length = 0;

        List<Character> list = new LinkedList<>();
        for(int index = 0; index!=s.length(); ){
            if(list.contains(arr[index])){
                list.remove(0);
                continue;
            }
            list.add(arr[index++]);
            length = Math.max(list.size(),length);
        }

        return length;
    }
}
```
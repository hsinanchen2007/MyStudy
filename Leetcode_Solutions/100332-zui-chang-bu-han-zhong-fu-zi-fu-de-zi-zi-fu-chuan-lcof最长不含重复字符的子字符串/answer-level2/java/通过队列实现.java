### 解题思路
1. 队列中没有这个字符，添加
2. 队列中有这个字符，从前往后，直到删除了他
3. 队列的长度记录下来，最长结果返回回去

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Queue<Character> queue =new LinkedList();
        char[] chars =s.toCharArray();
        int max=0;
        for(int i=0;i<chars.length;i++){
            if(queue.contains(chars[i])){
                while(queue.remove()!=chars[i]){
                    continue;
                }
                queue.add(chars[i]);
            }else{
                queue.add(chars[i]);
            }
            max=max>queue.size()?max:queue.size();
        }
        return max;
    }
}
```
### 解题思路
![image.png](https://pic.leetcode-cn.com/51b9dec4d9da893db64f2b091e7e6d978ac93242664c5f96c15004017676a2dc-image.png)

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
         Map<Character, Character> map = new HashMap<>();
        map.put('a', 'a');
        map.put('e', 'a');
        map.put('i', 'a');
        map.put('o', 'a');
        map.put('u', 'a');
        map.put('A', 'a');
        map.put('E', 'a');
        map.put('I', 'a');
        map.put('O', 'a');
        map.put('U', 'a');

        char[] arr = s.toCharArray();
        int pre = 0;
        int post = arr.length - 1;

        while (pre < post) {
            while (pre < post && !map.containsKey(arr[pre])) {
                pre++;
            }
            while (pre < post && !map.containsKey(arr[post])) {
                post--;
            }
            char tmp = arr[pre];
            arr[pre] = arr[post];
            arr[post] = tmp;
            pre++;
            post--;
        }
        return String.valueOf(arr);
    }
}
```
### 解题思路
用时3ms，非递归，使用快慢指针解决

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String cur = "1";
        for (int i = 1;i < n; i++){
            int left = 0;
            int j = 0;
            StringBuilder temp = new StringBuilder();
            for(j = 0;j < cur.length(); j++){
                if (cur.charAt(left) != cur.charAt(j)){
                    temp.append(j - left).append(cur.charAt(left) - '0');
                    left = j;//重新记录位置
                }
            }
            if (j - left > 0 && cur.charAt(left) == cur.charAt(cur.length() - 1)){
                temp.append(j - left).append(cur.charAt(cur.length() - 1) - '0');
            }
            cur = temp.toString();
        }
        return cur;
    }
}
```
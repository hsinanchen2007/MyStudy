### 解题思路
此处撰写解题思路
1、根据order的字母顺序，给予每个字母定义权重
2、words 中后一个跟前一个进行比较，比较的顺序是通过 order 定义的权重。

### 代码

```java
class Solution {

    private Map<Character, Integer> orders;

    /**
    * 排序
    */
    public boolean isAlienSorted(String[] words, String order) {
        if (words == null || words.length < 2 || order == null){
            return true;
        }
        initCharWeight(order);
        for (int i = 1;i < words.length;i ++) {
            if (compareTo(words[i - 1], words[i]) > 0) {
                return false;
            }
        }
        return true;
    }


    // 比较
    private int compareTo(String o1, String o2){
        int len1 = o1.length();
        int len2 = o2.length();
        int lim = Math.min(len1, len2);
        char v1[] = o1.toCharArray();
        char v2[] = o2.toCharArray();
        int k = 0;
        while (k < lim) {
        char c1 = v1[k];
        char c2 = v2[k];
        if (c1 != c2) {
            return orders.get(c1) - orders.get(c2);
        }
        k++;
        }
        return len1 - len2;
    }

    /**
    * 初始化字母的权重
    */
    private void initCharWeight(String order){
        orders = new HashMap<>(order.length());
        int l = order.length();
        for (int i = 0;i < l;i ++) {
            orders.put(order.charAt(i), i + 1);
        }
    }
}
```
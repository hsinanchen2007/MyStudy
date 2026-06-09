### 解题思路
回文串的特点：有序时是对称的，所以从两边开始划掉相同的元素，最后剩下的元素个数只能是0和1。无序时同样如此。可以使用java语言的集合
集合中存在该字符就删掉（偶数个数都划掉），不存在就添加，最后集合的大小只有0和1两种情况。
### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        Set set = new HashSet();
        char ch[] = s.toCharArray();
        for(char c : ch)
        {
            if(set.contains(c))
            {
                set.remove(c);
            }else{
                set.add(c);
            }
        }
        return set.size()<=1;
    }
}
```
### 解题思路
执行用时 :8 ms, 在所有 Java 提交中击败了5.59%的用户
内存消耗 :39.6 MB, 在所有 Java 提交中击败了6.67%的用户

### 代码


```java
class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int pos1 = 0, pos2 = 0;
        int minDistance = words.length;
        //初始化
        while(pos1<words.length && !words[pos1].equals(word1)) pos1++;
        while(pos2<words.length && !words[pos2].equals(word2)) pos2++;
                    

        while(pos1<words.length && pos2<words.length){
            minDistance = Math.min(minDistance, Math.abs(pos1-pos2));
            System.out.println(pos2 + " " +pos1);
            if(pos1 < pos2){
                pos1++;
                while(pos1<words.length && !words[pos1].equals(word1)) pos1++;//找到下一个候选索引
            }else{
                pos2++;
                while(pos2<words.length && !words[pos2].equals(word2)) pos2++;//找到下一个候选索引
            }
        }
        return minDistance;
    }
}
```
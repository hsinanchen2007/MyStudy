### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    static Set<String> strings;
    //普通回溯+递归：因为会遍历每种情况，所以时间复杂度为O(n的n次方)，需要加备忘录memo
    public static boolean wordBreak(String s, List<String> wordDict) {
        boolean flag ;
        //将List<String>变成HashSet，增加查询效率
        strings = new HashSet<>(wordDict);
        //备忘录，memo秩i代表以i为开始的子串无论是否被拆分，可以在字典中找到单词
        Boolean[] memo = new Boolean[s.length()];
        flag = recursion(s,0,memo);
        return flag;
    }

    private static boolean recursion(String s,int startIndex,Boolean[] memo){
        //递归基
        if (startIndex >= s.length()) return true;

        //查备忘录，减少重复计算，当前递归的以startIndex开始的子串，是否可以在字典中找到单词
        if (memo[startIndex] != null) return memo[startIndex];

        //递归体
        for (int i = startIndex;i<s.length();i++){
            //如果该子串在字典中
            if (strings.contains(s.substring(startIndex,i+1))){
                //继续递归剩下的部分
                boolean flag = recursion(s,i+1,memo);
                //如果剩下的部分也是在字典中，则返回true，并且在备忘录中增加记录，代表以该startIndex为开始的子串可以在字典中找到
                if (flag) {
                    memo[startIndex] = true;
                    return true;
                }
                else continue;//如果该子串不在字典中，,继续遍历
            }
        }
        //如果遍历完剩下的部分都没找到字典中的单词，则直接返回false，没有从startIndex开始的子串对应的单词，并给备忘录做好记录
        memo[startIndex] = false;
        return false;
    }

}
```
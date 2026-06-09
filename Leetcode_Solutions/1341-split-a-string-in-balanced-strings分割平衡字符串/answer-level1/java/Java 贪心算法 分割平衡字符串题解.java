问题分析：分割平衡串，得到尽可能多的平衡串。这是一个适用贪心算法的问题，在适当的位置截断源串得到平衡子串，截断后前后子串的计数不互相影响（无后效性），且所有局部最优相加即为整体的最优解。
解决思路：
1. 设置一个'L'与'R'的差值计数器diffCount，设置一个平衡子串计数器count；
2. 顺序遍历源串字符，遇L则diffCount+1，遇到R则diffCount-1；
3. 每遍历一个字符检查一次diffCount是否为0，若为0则count+1

```
class Solution {
    public int balancedStringSplit(String s) {
        if (s == null || "".equals(s)) {
            return 0;
        }
        int count = 0, diffCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'L') {
                diffCount++;
            } else {
                diffCount--;
            }
            if (diffCount == 0) {
                count ++;
            }
        }
        return count;
    }
}
```

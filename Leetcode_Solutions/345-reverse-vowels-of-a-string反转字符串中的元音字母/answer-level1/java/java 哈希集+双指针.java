执行用时 : 15 ms , 在所有 Java 提交中击败了 66.60% 的用户 内存消耗 : 41.8 MB , 在所有 Java 提交中击败了 60.37% 的用户 

先用哈希集合记录元音字母，再用双指针筛选出前后元音字母进行置换
```
    public String reverseVowels(String s) {
        Set<Character> set = new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        set.add('A');
        set.add('E');
        set.add('I');
        set.add('O');
        set.add('U');
        char[] strs = s.toCharArray();
        int start = 0;
        int end = strs.length - 1;
        while (start < end) {
            while (!set.contains(strs[start]) && start < end) {
                start++;
            }
            while (!set.contains(strs[end]) && start < end) {
                end--;
            }
            Character temp = strs[start];
            strs[start] = strs[end];
            strs[end] = temp;
            start++;
            end--;
        }
        return String.valueOf(strs);
    }
```

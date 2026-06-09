![image.png](https://pic.leetcode-cn.com/8ad9fc478a28e22f33d2ee40b41c9498d15e77d1e38a642444e97cda4c1607d8-image.png)

```
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        int[] s1Arr = new int [26];
        char[] s1Ch = s1.toCharArray();
        char[] s2Ch = s2.toCharArray();
        for (char c : s1Ch) {
            s1Arr[c - 'a']++;
        }
        for (char c : s2Ch) {
            s1Arr[c - 'a']--;
            if (s1Arr[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        Solution solution = new Solution();
        boolean flag = solution.CheckPermutation(s1, s2);
        System.out.println(flag);
    }
}
```


```
class Solution {
    public String reverseWords(String s) {
        if (s == null || s.length() < 2) {
            return s;
        }
        char[] arr = s.toCharArray();
        int l = 0;
        int r = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == ' ') {
                while (l < r) {
                    char t = arr[l];
                    arr[l] = arr[r];
                    arr[r] = t;
                    l++;
                    r--;
                }
                l = i + 1;
                r = i + 1;
            } else {
                r = i;
            }
        }
        while (l < r) {
            char t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
            l++;
            r--;
        }
        return new String(arr);
    }
}
```
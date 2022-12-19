```
    class Solution {
        public void reverseString(char[] s) {

            int head = 0;
            int last = s.length - 1;

            while (head < last) {
                swap(s, head++, last--);
            }
        }

        private void swap(char[]s, int a, int b) {
            char temp = s[a];
            s[a] = s[b];
            s[b] = temp;
        }
    }
```

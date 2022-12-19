```java
class Solution {
    public String minWindow(String S, String T) {
        List<Integer>[] lists = new List[26];
        for (int i = 0; i < 26; i++) {
            lists[i] = new ArrayList<>();
        }
        int[] pos = new int[26];
        for (int i = 0; i < T.length(); i++) {
            pos[T.charAt(i) - 'a']++;
        }
        for (int i = 0; i < S.length(); i++) {
            if (pos[S.charAt(i) - 'a'] > 0) {
                lists[S.charAt(i) - 'a'].add(i);
            }
        }

        int[] index = new int[T.length()];
        int i = 0;
        int min = -1, minL = 0, minR = 0;
        while (true) {
            List<Integer> list = lists[T.charAt(i) - 'a'];
            if (index[i] >= list.size()) {
                break;
            }

            if (i > 0) {
                List<Integer> listPre = lists[T.charAt(i - 1) - 'a'];
                if (list.get(index[i]) <= listPre.get(index[i - 1])) {
                    index[i]++;
                    continue;
                }
            }

            if (i < T.length() - 1 && index[i] < list.size() - 1) {
                List<Integer> listPost = lists[T.charAt(i + 1) - 'a'];
                if (list.get(index[i] + 1) < listPost.get(index[i + 1])) {
                    index[i]++;
                    continue;
                }
            }

            if (i == T.length() - 1) {
                List<Integer> listL = lists[T.charAt(0) - 'a'];
                List<Integer> listR = lists[T.charAt(i) - 'a'];
                if (listR.get(index[i]) - listL.get(index[0]) < min || min == -1) {
                    min = listR.get(index[i]) - listL.get(index[0]);
                    minL = listL.get(index[0]);
                    minR = listR.get(index[i]);
                }
                i = 0;
                index[i]++;
            } else {
                i++;
            }
        }

        if (min == -1) {
            return "";
        }

        return S.substring(minL, minR + 1);
    }
}
```
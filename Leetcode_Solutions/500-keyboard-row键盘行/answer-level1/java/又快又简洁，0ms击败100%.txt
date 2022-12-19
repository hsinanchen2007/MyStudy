```java
class Solution {
    public String[] findWords(String[] words) {
        ArrayList<String> list = new ArrayList<>();
        int[] temp = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
        outer: for (int i = 0; i < words.length; i++) {
            char[] arr = words[i].toCharArray();
            int pos = -1;
            for (int j = 0; j < arr.length; j++) {
                char c = Character.toLowerCase(arr[j]);
                if (pos != -1 && temp[c - 'a'] != pos) {
                    continue outer;
                }
                pos = temp[c - 'a'];
            }
            list.add(words[i]);
        }
        return list.toArray(new String[0]);
    }
}
```
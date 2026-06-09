### 解题思路
bellman-ford算法

### 代码

```java

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;


class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] words = {
                "z",
                "z"
        };
        String s = solution.alienOrder(words);
        System.out.println("s = " + s);
    }


    public String alienOrder(String[] words) {
        //bellman-ford算法
        ArrayList<Edge> list = new ArrayList<>();
        // 构造边 list
        for (int i = 0; i < words.length; i++) {
            for (int j = i + 1; j < words.length; j++) {
                String s1 = words[i];
                String s2 = words[j];
                cmp(s1, s2, list);
            }
        }
        //冒泡排序
        ArrayList<Character> charList = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            for (Edge edge : list) {
                char from = edge.from;
                char to = edge.to;
                if (from == to) {
                    if (!charList.contains(from)) charList.add(from);
                    continue;
                }
                if (charList.contains(from) && charList.contains(to)) {
                    int f = charList.indexOf(from);
                    int t = charList.indexOf(to);
                    if (f > t) {
                        // 交换
                        charList.set(f, to);
                        charList.set(t, from);
                    }
                } else if (charList.contains(from) && !charList.contains(to)) {
                    charList.add(to);
                } else if (!charList.contains(from) && charList.contains(to)) {
                    charList.add(0, from);
                } else {
                    charList.add(from);
                    charList.add(to);
                }
            }
        }
        boolean isOrdered = check(charList, list);
        if (!isOrdered) return "";
        HashSet<Character> set = new HashSet<>();
        for (String word : words) {
            char[] chars = word.toCharArray();
            for (char c : chars) {
                set.add(c);
            }
        }
        String res = "";
        for (Character character : charList) {
            res += character;
            set.remove(character);
        }
        for (Character character : set) {
            res+=character;
        }
        return res;
    }

    private boolean check(ArrayList<Character> charList, ArrayList<Edge> list) {
        for (Edge edge : list) {
            char from = edge.from;
            char to = edge.to;
            int f = charList.indexOf(from);
            int t = charList.indexOf(to);
            if (f > t) return false;
        }
        return true;
    }

    private void cmp(String s1, String s2, ArrayList<Edge> list) {
        char[] array = s1.toCharArray();
        char[] charArray = s2.toCharArray();
        int i = 0;
        while (i < array.length && i < charArray.length) {
            if (array[i] != charArray[i]) {
                list.add(new Edge(array[i], charArray[i]));
                return;
            }
            i++;
        }
        list.add(new Edge(array[i - 1], charArray[i - 1]));
    }


    class Edge {
        char from;
        char to;

        public Edge(char from, char to) {
            this.from = from;
            this.to = to;
        }
    }
}

```
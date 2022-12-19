```
class Solution {
    public int openLock(String[] deadends, String target) {
         List<String> deadEndsList = Arrays.asList(deadends);
        if (deadEndsList.contains("0000")) {
            return -1;
        }
       
        Queue<String> q = new LinkedList<>();
        q.add("0000");
        int step = 0;
        Set<String> used = new HashSet<>();
        while (!q.isEmpty()) {
            step++;
            int size = q.size();
          
            for (int i = 0; i < size; i++) {
                String data = q.poll();
                if (deadEndsList.contains(data)) {
                    continue;
                }
                if (target.equals(data)) {
                    return step-1;
                }
                char[] charArray = data.toCharArray();
                String n1 = String.valueOf(Character.digit(charArray[0], 9) + 1) + data.substring(1);
                String n2 = data.substring(0, 1) + String.valueOf(Character.digit(charArray[1], 9) + 1) + data.substring(2);
                String n3 = data.substring(0, 2) + String.valueOf(Character.digit(charArray[2], 9) + 1) + data.substring(3);
                String n4 = data.substring(0, 3) + String.valueOf(Character.digit(charArray[3], 9) + 1);
                String n5 = String.valueOf((Character.digit(charArray[0], 10) - 1) >= 0 ? Character.digit(charArray[0], 10) - 1 : 9) + data.substring(1);
                String n6 = data.substring(0, 1) + String.valueOf((Character.digit(charArray[1], 10) - 1) >= 0 ? Character.digit(charArray[1], 10) - 1 : 9) + data.substring(2);
                String n7 = data.substring(0, 2) + String.valueOf((Character.digit(charArray[2], 10) - 1) >= 0 ? Character.digit(charArray[2], 10) - 1 : 9) + data.substring(3);
                String n8 = data.substring(0, 3) + String.valueOf((Character.digit(charArray[3], 10) - 1) >= 0 ? Character.digit(charArray[3], 10) - 1 : 9);
                if (!used.contains(n8) && !deadEndsList.contains(n8)) {
                    q.add(n8);
                    used.add(n8);
                }
                if (!used.contains(n7) && !deadEndsList.contains(n7)) {
                    q.add(n7);
                    used.add(n7);
                }
                if (!used.contains(n6) && !deadEndsList.contains(n6)) {
                    q.add(n6);
                    used.add(n6);
                }
                if (!used.contains(n5) && !deadEndsList.contains(n5)) {
                    q.add(n5);
                    used.add(n5);
                }
                if (!used.contains(n4) && !deadEndsList.contains(n4)) {
                    q.add(n4);
                    used.add(n4);
                }
                if (!used.contains(n3) && !deadEndsList.contains(n3)) {
                    q.add(n3);
                    used.add(n3);
                }
                if (!used.contains(n2) && !deadEndsList.contains(n2)) {
                    q.add(n2);
                    used.add(n2);

                }
                if (!used.contains(n1) && !deadEndsList.contains(n1)) {
                    q.add(n1);
                    used.add(n1);
                }

            }
        }
        return -1;
    }
}
```

public int firstUniqChar(String s) {
        int index = -1;
        Set<Character> set = new HashSet<Character>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (set.contains(c)) {
                continue;
            }
            set.add(c);
            boolean flag = true;
            for (int j = i + 1; j < s.length(); j++) {
                if (c == s.charAt(j)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                index = i;
                break;
            }
        }

        return index;
}

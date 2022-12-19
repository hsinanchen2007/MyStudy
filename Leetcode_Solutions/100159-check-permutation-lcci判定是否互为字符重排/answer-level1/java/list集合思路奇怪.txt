 public boolean CheckPermutation(String s1, String s2) {
        if(s1.length() != s2.length()) return false;
        List<Character> list = new ArrayList<>();
        char[] char1 = s1.toCharArray();
        char[] char2 = s2.toCharArray();
        for(Character data : char1) {
            list.add(data);
        }
        for(Character data : char2) {
            if(list.contains(data)) {
                list.remove(data);
            }
        }
        return list.size() == 0;
    }
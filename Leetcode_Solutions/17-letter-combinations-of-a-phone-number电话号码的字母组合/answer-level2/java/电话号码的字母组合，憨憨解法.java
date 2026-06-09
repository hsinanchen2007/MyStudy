感觉自己只会硬解，每题都是硬解(循环撸到底)。
用的是递归循环出来的。


    public List<String> letterCombinations(String digits) {
        List<String> list = new ArrayList<>();
        HashMap<Integer, String> map = new HashMap<>();
        map.put(2, "abc");
        map.put(3, "def");
        map.put(4, "ghi");
        map.put(5, "jkl");
        map.put(6, "mno");
        map.put(7, "pqrs");
        map.put(8, "tuv");
        map.put(9, "wxyz");

        for (int i = 0; i < digits.length(); i++) {
            String s = map.get(Integer.parseInt(String.valueOf(digits.charAt(i))) );
            list = getNewString(list, s);
        }
        return list;
    }
      private static List<String> getNewString(List<String> oldStrList, String s) {
        char[] chars = s.toCharArray();
        List<String> listNew = new ArrayList<>();
        if (oldStrList == null || oldStrList.size() == 0) {
            for (int j = 0; j < chars.length; j++) {
                listNew.add(String.valueOf(chars[j]));
            }
        }
        for (int i = 0; i < oldStrList.size(); i++) {
            for (int j = 0; j < chars.length; j++) {
                listNew.add(oldStrList.get(i) + chars[j]);
            }
        }
        return listNew;
    }


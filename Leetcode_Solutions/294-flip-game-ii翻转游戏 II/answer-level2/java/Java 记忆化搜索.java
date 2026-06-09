    private Map<String,Boolean> hmap = new HashMap<>();;
    public boolean canWin(String s) {
        if(hmap.containsKey(s)) return hmap.get(s);
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) == '+' && s.charAt(i-1) == '+'){
                String ss = s.substring(0, i - 1) + "--" + s.substring(i + 1);
                if(!canWin(ss)) {
                    hmap.put(ss,false);
                    return true;
                }
                hmap.put(ss,true);
            }
        }
        return false;
    }
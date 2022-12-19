    public String[] uncommonFromSentences(String A, String B) {
        StringBuilder sb = new StringBuilder();
        String res = sb.append(A).append(" ").append(B).toString();
        String[] tmp = res.split(" ");
        Map<String, Integer> map = new HashMap<>();
        for(String str: tmp) {
            if(map.containsKey(str)) {
                map.put(str, map.get(str) + 1);
            } else {
                map.put(str, 1);
            }
        }
        List<String> list = new ArrayList<>();
        for(Map.Entry<String, Integer> entry : map.entrySet()) {
            if(entry.getValue() == 1) {
                list.add(entry.getKey());
            }
        }
        return list.toArray(new String[list.size()]);
    }
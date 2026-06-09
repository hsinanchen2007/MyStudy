class Solution {
    public static List<String> subdomainVisits(String[] cpdomains) {
        HashMap<String, Integer> res = new HashMap<>();
        List<String> ls = new ArrayList<>();
        for (String domain : cpdomains) {
            String[] content = domain.split(" ");
            int count = Integer.parseInt(content[0]);
            //获取每个子域名
            String[] rest = content[1].split("\\.");
            for (int i = rest.length - 1; i >= 0; i--) {
                //先组合成xxxxx.com
                String val = "";
                for (int j = i; j < rest.length; j++) {
                    val = val + rest[j] + ".";
                }
                //去掉com后面的.
                val = val.substring(0, val.length() - 1);
                //如果map里面有就更新值，没有就加进去
                if (res.containsKey(val)) {
                    int temp = res.get(val);
                    res.put(val, temp + count);
                } else {
                    res.put(val, count);
                }
            }
        }
        for (Map.Entry entry : res.entrySet()) {
            ls.add(entry.getValue() + " " + entry.getKey());
        }
        return ls;
    }
}
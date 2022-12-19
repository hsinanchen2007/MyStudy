利用set对匹配的去重
空间复杂度有点高
public static boolean wordPattern(String pattern, String str) {
        /**
         * 只有两种情况为false:
         * 1.键相同值不相同
         * 2.键不相同值相同
         */
        if (pattern == null || str == null) return false;
        String[] split = str.split(" ");
        if (pattern.length() != split.length) return false;
        Map<Character, String> map = new HashMap<>();
        Set<String> set = new HashSet<>();
        
        for (int i = 0; i < pattern.length(); i++) {
            if (!map.containsKey(pattern.charAt(i))) {
                // 键不相同，值相同
                if (set.add(split[i])) {
                    map.put(pattern.charAt(i), split[i]);
                } else {
                    return false;
                }
            } else {
                // 键相同，值不是原来匹配的值
                if (!map.get(pattern.charAt(i)).equals(split[i])) {
                    return false;
                }
            }
        }
        return true;
    }
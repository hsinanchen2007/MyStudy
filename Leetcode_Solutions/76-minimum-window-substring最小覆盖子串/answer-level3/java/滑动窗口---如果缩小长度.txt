class Solution {
    // 尽量移动窗口的begin，使得长度缩小，和第3题相反，得想好什么情况下移动begin和i（尾指针）
    public String minWindow(String s, String t) {
        int[] map_s = new int[128]; // 用来判断窗口是否包含t
        int[] map_t = new int[128]; // 保存t
        List<Character> list = new ArrayList<>();
        for (int i = 0; i < t.length(); i++) {
            map_t[t.charAt(i)]++;
        }
        for(int i = 0; i < 128; i++) {
            if (map_t[i] != 0) {
                list.add((char) i);
            }
        }
        int begin = 0;
        String result = "";
        for (int i = 0; i < s.length(); i++) {
            map_s[s.charAt(i)]++;
            while (begin < i) {
                char beginChar = s.charAt(begin);
                if (map_t[beginChar] == 0) { // 窗口起始不在t里面
                    begin++;
                } else if (map_s[beginChar] > map_t[beginChar]) { // 窗口起始在t里面，其个数大于t中对应字符的个数
                    map_s[beginChar]--;
                    begin++;
                } else {
                    break;
                }
            }
            if (judge(map_s, map_t, list)) {
                if (result == "" || i - begin + 1 < result.length()) {
                    result = s.substring(begin, i + 1);
                }
            }
        }

        return result;
    }

    boolean judge(int[] map_s, int[] map_t, List<Character> list) {
        for (int i = 0; i < list.size(); i++) {
            if (map_s[list.get(i)] < map_t[list.get(i)]) {
                return false;
            }
        }
        return true;
    }
}
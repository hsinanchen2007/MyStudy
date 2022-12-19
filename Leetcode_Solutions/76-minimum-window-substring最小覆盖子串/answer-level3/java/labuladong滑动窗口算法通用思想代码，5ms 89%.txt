class Solution {
    public String minWindow(String s, String t) {

        int l = 0, r = 0, total = t.length(), number = s.length() + 1, index = 0;
        int[] needs = new int[256], windows = new int[256];

        for (char ch : t.toCharArray()) needs[ch - 'A']++;

        while (r < s.length()) {
            char ch1 = s.charAt(r);
            if (needs[ch1 - 'A'] > 0) {
                windows[ch1 - 'A']++;
                if (windows[ch1 - 'A'] <= needs[ch1 - 'A']) total--;
            }
            while (total == 0) {
                if (number > r - l + 1) {
                    index = l;
                    number = r - l + 1;
                }
                char ch2 = s.charAt(l);
                if (needs[ch2 - 'A'] > 0) {
                    windows[ch2 - 'A']--;
                    if (windows[ch2 - 'A'] < needs[ch2 - 'A']) total++;
                }
                l++;
            }
            r++;
        }
        if (number==s.length()+1)return "";

        return s.substring(index, index + number);  //截取字符串
    }
}
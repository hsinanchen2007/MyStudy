class Solution {
    public String convert(String s, int numRows) {
if (numRows == 1)
            return s;
        StringBuilder rs = new StringBuilder();
        for (int i = 0; i < numRows && i<s.length(); i++) {
            rs.append(s.charAt(i));
            for (int k = 2; ; k += 2) {
                int index = 0;
                if (i != 0 && i != (numRows - 1)) {
                    index = k * (numRows - 1) - i;
                    if (index >= 0 && index < s.length()) {
                        rs.append(s.charAt(index));
                    } else
                        break;
                }

                index = i + k * (numRows - 1);
                if (index >= 0 && index < s.length()) {
                    rs.append(s.charAt(index));
                } else
                    break;
            }
        }
        return rs.toString();
    }
}
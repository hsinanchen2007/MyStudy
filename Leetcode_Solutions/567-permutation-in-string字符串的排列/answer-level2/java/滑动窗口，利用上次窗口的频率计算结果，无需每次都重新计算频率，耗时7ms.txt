```
class Solution {
    private static final byte ALPHABET_OFFSET = 97;

    public boolean checkInclusion(String s1, String s2) {
        int window = s1.length();
        byte[] s1Frequency = getFrequency(s1);
        byte[] frequency = null;
        char head = 0;
        for (int i = 0; i <= s2.length() - window; i++) {
            if (frequency == null) {
                String substr = s2.substring(i, i + window);
                frequency = getFrequency(substr);
            } else {
                // 掐头去尾，利用上一次的结果，只需要修改头和尾的频率即可
                frequency[head - ALPHABET_OFFSET]--;
                frequency[s2.charAt(i + window - 1) - ALPHABET_OFFSET]++;
            }
            head = s2.charAt(i);
            if (arrayEquals(s1Frequency, frequency)) {
                return true;
            }
        }
        return false;
    }

    private byte[] getFrequency(String string) {
        byte[] frequencyTable = new byte[26];
        for (char letter : string.toCharArray()) {
            frequencyTable[letter - ALPHABET_OFFSET]++;
        }
        return frequencyTable;
    }

    private boolean arrayEquals(byte[] fre1, byte[] fre2) {
        return Arrays.equals(fre1, fre2);
    }
}
```

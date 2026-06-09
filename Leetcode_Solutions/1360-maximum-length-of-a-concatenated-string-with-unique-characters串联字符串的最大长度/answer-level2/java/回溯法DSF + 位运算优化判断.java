class Solution {
    String result = "";
    private static Map<String, Integer> cacheBit = new HashMap<>();

    public int maxLength(List<String> arr) {
        if (arr.size() == 1) {
            return arr.get(0).length();
        }

        // init.
        cacheBit.clear();
        for (String node : arr) {
            int bit = 0;
            for (char c : node.toCharArray()) {
                int b = 1 << (c - 'a');
                if ((b & bit) > 0) {
                    bit = 0;
                    break;
                } else {
                    bit = bit | b;
                }
            }
            cacheBit.put(node, bit);
        }

        backtrace("", 0, 0, arr, 0);
        return result.length();
    }

    void backtrace(String before, int bbit, int length, List<String> arr, int index) {
        // System.out.println(before + " " + index + " " + length);
        if (length > result.length()) {
            result = before;
        }
        if (index == arr.size()) {
            return;
        }

//        for (int i = index; i < arr.size(); i++) {
        String node = arr.get(index);
        //不加

        backtrace(before, bbit, length, arr, index + 1);

        //加入
        int nbit = cacheBit.get(node);
        if (nbit != 0 && (nbit & bbit) == 0) {
            backtrace(before + node, (nbit | bbit), length + node.length(), arr, index + 1);
        }

//        }
    }
}
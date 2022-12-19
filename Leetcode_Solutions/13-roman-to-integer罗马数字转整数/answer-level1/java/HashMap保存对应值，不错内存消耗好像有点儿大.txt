class Solution {
    public int romanToInt(String s) {
HashMap<String, Integer> maps = new HashMap<>();
        maps.put("I", 1);
        maps.put("V", 5);
        maps.put("X", 10);
        maps.put("L", 50);
        maps.put("C", 100);
        maps.put("D", 500);
        maps.put("M", 1000);

        int strLength = s.length();
        if (strLength == 1) {
            return maps.get(s);
        }

        int resultInt = 0;
        int step = 0;//默认步幅为0
        for (int i = 0; i < strLength; i=i+1+step) {

            //最后一位
            if (i == strLength - 1) {
                resultInt += maps.get(String.valueOf(s.charAt(i)));
                break;
            }

            String currentStr = String.valueOf(s.charAt(i));
            String nextStr = String.valueOf(s.charAt(i + 1));

            int currentInt = maps.get(currentStr);
            int nextInt = maps.get(nextStr);

            if (currentInt < nextInt) {
                resultInt += nextInt - currentInt;
                step = 1;
            } else {
                step = 0;
                resultInt += currentInt;
            }

        }

        return resultInt;
    }
}
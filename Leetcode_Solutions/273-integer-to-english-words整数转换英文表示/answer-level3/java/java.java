private static final int[] system1 = {1000000000, 1000000, 1000};

    private static final String[] system1Strs = {"Billion", "Million", "Thousand"};

    private static final int[] system2 = {
            100, 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10
    };

    private static final String[] system2Strs = {
            "Hundred", "Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty", "Nineteen",
            "Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten"
    };

    private static final Map<Integer, String> map = new HashMap<Integer, String>() {{
        put(9, "Nine");
        put(8, "Eight");
        put(7, "Seven");
        put(6, "Six");
        put(5, "Five");
        put(4, "Four");
        put(3, "Three");
        put(2, "Two");
        put(1, "One");
    }};

    public static String numberToWords(int nums) {
        if (nums == 0) {
            return "Zero";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < system1.length; i++) {
            int v = nums / system1[i];
            if (v > 0) {
                sb.append(numLessThousandToWords(v) + " " + system1Strs[i]).append(" ");
            }
            nums %= system1[i];
        }
        if (nums > 0) {
            sb.append(numLessThousandToWords(nums)).append(" ");
        }
        return sb.substring(0, sb.length() - 1);
    }

    private static String numLessThousandToWords(int nums) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < system2.length; i++) {
            int v = nums / system2[i];
            if (v > 0) {
                if (i == 0) {
                    sb.append(map.get(v)).append(" ").append(system2Strs[i]).append(" ");
                    nums %= system2[i];
                } else {
                    if (v == 1) {
                        sb.append(system2Strs[i]).append(" ");
                        nums %= system2[i];
                        break;
                    }
                }
            }
        }
        if (nums > 0) {
            sb.append(map.get(nums)).append(" ");
        }
        return sb.substring(0, sb.length() - 1);
    }
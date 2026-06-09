public String sortString(String s) {
        int[] array = new int[26];
        for (char c : s.toCharArray()) {
            array[c - 'a']++;
        }
        StringBuilder result = new StringBuilder();
        while (true) {

            boolean find = false;
            for (int i = 0; i < array.length; i++) {
                if (array[i] > 0) {
                    find = true;
                    result.append((char) ('a' + i));
                    array[i]--;
                }
            }
            for (int i = array.length - 1; i >= 0; i--) {
                if (array[i] > 0) {
                    find = true;
                    result.append((char) ('a' + i));

                    array[i]--;
                }
            }
            if (!find) {
                break;
            }

        }
        return result.toString();

    }

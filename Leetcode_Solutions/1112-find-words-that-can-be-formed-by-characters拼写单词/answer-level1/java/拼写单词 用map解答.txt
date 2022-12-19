
    @TargetApi(24)
    public static int countCharacters(String[] words, String chars) {

        int result = 0;
        char[] charArray = chars.toCharArray();
        Map<Character, Integer> map = new HashMap<>();
        Map<Character, Integer> tmpmap = new HashMap<>();

        for (int i = 0; i < charArray.length; i++) {
            int m = map.getOrDefault(charArray[i], 0);
            map.put(charArray[i], m + 1);
        }

        for (int i = 0; i < words.length; i++) {
            char[] word = words[i].toCharArray();
            boolean contain = true;

            tmpmap.clear();
            for (Map.Entry<Character, Integer> m : map.entrySet()) {
                tmpmap.put(m.getKey(), m.getValue());
            }


            for (int j = 0; j < word.length; j++) {
                if (tmpmap.containsKey(word[j])) {
                    tmpmap.put(word[j], tmpmap.get(word[j]) - 1);
                    if (tmpmap.get(word[j]) == -1) {
                        break;
                    }
                } else {
                    contain = false;
                    break;
                }
            }

            if (!tmpmap.containsValue(-1) && contain) {
                result += word.length;
            }

        }

        return result;
    }
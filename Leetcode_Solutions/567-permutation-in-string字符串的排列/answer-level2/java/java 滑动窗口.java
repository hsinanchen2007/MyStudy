```
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) return false;

        HashMap<Character, Integer> s1Counter = new HashMap<>();
        HashMap<Character, Integer> matcher = new HashMap<>();
        for (char s:
             s1.toCharArray()) {
                s1Counter.put(s, s1Counter.containsKey(s)?s1Counter.get(s)+1:1);
                matcher.put(s, 0);
        }
        System.out.println(s1Counter.toString());
        Queue<Character> slider = new LinkedList<>();
        HashMap<Character, Integer> macherSlider = new HashMap<>(matcher);

        int len = s1.length();
        for (int i = 0; i < s2.length(); i++) {
            char c = s2.charAt(i);
            if (!s1Counter.containsKey(c)) {
                slider.clear();
                macherSlider.putAll(matcher);
                continue;
            }

            while (!slider.isEmpty() && macherSlider.get(c) >= s1Counter.get(c)) {
                Character head = slider.poll();
                macherSlider.put(head, macherSlider.get(head)-1);
            }
            macherSlider.put(c, macherSlider.get(c)+1);
            slider.offer(c);
            if (slider.size() == len) {
                return true;
            }
        }
        return false;
    }
```
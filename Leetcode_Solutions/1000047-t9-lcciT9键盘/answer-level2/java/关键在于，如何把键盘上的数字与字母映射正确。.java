创建一个哈希表，key代表键盘上的数字，value代表该数字所包含的子母集合。
```
public List<String> getValidT9Words(String num, String[] words) {
        Map<Character, Set<Character>> map = new HashMap<>();
        Set<Character> set2 = new HashSet<>();
        set2.add('a');
        set2.add('b');
        set2.add('c');
        map.put('2', set2);

        Set<Character> set3 = new HashSet<>();
        set3.add('d');
        set3.add('e');
        set3.add('f');
        map.put('3', set3);
        Set<Character> set4 = new HashSet<>();
        set4.add('g');
        set4.add('h');
        set4.add('i');
        map.put('4', set4);
        Set<Character> set5 = new HashSet<>();
        set5.add('j');
        set5.add('k');
        set5.add('l');
        map.put('5', set5);
        Set<Character> set6 = new HashSet<>();
        set6.add('m');
        set6.add('n');
        set6.add('o');
        map.put('6', set6);
        Set<Character> set7 = new HashSet<>();
        set7.add('p');
        set7.add('q');
        set7.add('r');
        set7.add('s');
        map.put('7', set7);
        Set<Character> set8 = new HashSet<>();
        set8.add('t');
        set8.add('u');
        set8.add('v');
        map.put('8', set8);
        Set<Character> set9 = new HashSet<>();
        set9.add('w');
        set9.add('x');
        set9.add('y');
        set9.add('z');
        map.put('9', set9);

        boolean[] flag = new boolean[words.length];
        Arrays.fill(flag, true);

        for (int i = 0; i < num.length(); ++i) {
            Set<Character> set = map.get(num.charAt(i));
            for (int j = 0; j < words.length; ++j) {
                if (!flag[j]) {
                    continue;
                } else if (!set.contains(words[j].charAt(i))) {
                    flag[j] = false;
                }
            }
        }
        List<String> result = new ArrayList<>();
        for (int i = 0; i < flag.length; ++i) {
            if (flag[i]) {
                result.add(words[i]);
            }
        }
        return result;

   

    }
```

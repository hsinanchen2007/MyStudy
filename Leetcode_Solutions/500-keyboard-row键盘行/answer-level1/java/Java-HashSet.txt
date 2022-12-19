主要利用hashset中的contains()进行判断
```
public String[] findWords(String[] words) {
        char[] arr1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        char[] arr2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        char[] arr3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        Set<Character> set1 = new HashSet<>();
        for (int i=0; i<arr1.length; i++) {
            set1.add(arr1[i]);
        }
        Set<Character> set2 = new HashSet<>();
        for (int i=0; i<arr2.length; i++) {
            set2.add(arr2[i]);
        }
        Set<Character> set3 = new HashSet<>();
        for (int i=0; i<arr3.length; i++) {
            set3.add(arr3[i]);
        }
        List<String> store = new ArrayList<>();
        for (int i=0; i<words.length; i++) {
            boolean flag1 = true;
            boolean flag2 = true;
            boolean flag3 = true;
            for (int j=0; j<words[i].length(); j++) {
                if (!set1.contains(words[i].toLowerCase().charAt(j)))
                    flag1 = false;
                if (!set2.contains(words[i].toLowerCase().charAt(j)))
                    flag2 = false;
                if (!set3.contains(words[i].toLowerCase().charAt(j)))
                    flag3 = false;
            }
            if (flag1 || flag2 || flag3) {
                store.add(words[i]);
            }
        }
        String[] output = new String[store.size()];
        for (int i=0; i<output.length; i++) {
            output[i] = store.get(i);
        }
        return output;
    }
```

```
String[] arr = {
            ".-",
            "-...",
            "-.-.",
            "-..",
            ".",
            "..-.",
            "--.",
            "....",
            "..",
            ".---",
            "-.-",
            ".-..",
            "--",
            "-.",
            "---",
            ".--.",
            "--.-",
            ".-.",
            "...",
            "-",
            "..-",
            "...-",
            ".--",
            "-..-",
            "-.--",
            "--.."
    };

    public int uniqueMorseRepresentations(String[] words) {
        HashSet<String> set = new HashSet<>();
        for (String str : words) {
            StringBuilder res = new StringBuilder();
            for (char c : str.toCharArray()) {
                res.append(arr[c - 'a']);
            }
            set.add(res.toString());
        }
        return set.size();
    }
```

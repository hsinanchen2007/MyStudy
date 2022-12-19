```
class Solution {
    public int compress(char[] chars) {
        int index = 1;
        int count = 1;
        for (int i = 1; i < chars.length; i++) {
            if (chars[i] == chars [i - 1]) {
                count++;
            }else {
                if (count > 1) {
                    char []temp = String.valueOf(count).toCharArray();
                    for (int j = 0; j < temp.length; j++) {
                        chars[index++] = temp[j];
                    }
                    count = 1;
                }
                chars[index++] = chars[i];
            }
        }
        if (count > 1) {
            char []temp = String.valueOf(count).toCharArray();
            for (int j = 0; j < temp.length; j++) {
                chars[index++] = temp[j];
            }
        }
        return index;
    }
}
```
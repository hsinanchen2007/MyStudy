```
public int countCharacters(String[] words, String chars) {
    if (chars == null || words == null)
        return 0;

    int lenC = chars.length();
    int lenW = words.length;

    if (lenW == 0)
        return 0;

    if (lenC == 0)
        return 0;

    int i = 0, j = 0 , lenS, index;
    int[] dict = new int[26];
    int result = 0;
    int count = 0;
    
    for (i = 0; i < lenW; i++) {
        String s = words[i];
        fill_dict(dict, chars);
        count = 0;
        for (j = 0, lenS = s.length(); j < lenS; j++) {
            index = s.charAt(j) - 'a';
            if (dict[index] != -1) {
                if (dict[index] != 0) {
                    count++;
                    dict[index]--;
                } else {
                    count = 0;
                    break;
                }
            } else {
                count = 0;
                break;
            }
        }
        result += count;
    }

    return result;
}

private void fill_dict(int[] dict, String chars) {
    int i = 0;
    int lenC = chars.length();
    int index;
    Arrays.fill(dict, -1);
    for (i = 0; i < lenC; i++) {
        index = chars.charAt(i) - 'a';
        if(dict[index] == -1){
            dict[index] =1;
        }else{
            dict[index]++;
        }
    }   
}
```

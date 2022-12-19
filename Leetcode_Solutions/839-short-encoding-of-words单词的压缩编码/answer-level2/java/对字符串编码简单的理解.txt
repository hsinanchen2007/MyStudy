**算法思想**
    先将字符串数组排序，将长的字符串放前面，短的放后面，长的会先添加，短的判断添加过的字符串是否包含了这个短的字符串，若包含，则进行添加下一个。
```
class Solution {
public int minimumLengthEncoding(String[] words) {
        String[] words2 =  Arrays.stream(words).sorted(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return -(o1.length() - o2.length());
            }
        }).toArray(String[]::new);
        String S = "";
        List<Integer> indexes = new ArrayList<>();
        CharSequence charSequence;
        int preLen = 0;
        for (int i = 0; i < words2.length; i++) {
            charSequence = words2[i] + "#";
            if ("".equals(S)) {
                S = S.concat(words2[i]+"#");
                indexes.add(0);
                preLen = words2[i].length();
            } else if (!S.contains(charSequence)) {
                S = S.concat(words2[i]+"#");
                preLen += 1;
                indexes.add(preLen);
                preLen += (words2[i].length());
            } else {
                indexes.add(S.indexOf(words2[i]));
            }

        }
        return S.length();

    }
}
```

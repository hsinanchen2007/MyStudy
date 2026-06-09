```Java []
class Solution {
    /**
     * 哈希表:字符->数字映射
     * @param digits
     * @return
     */
    public List<String> letterCombinations(String digits) {
        if(digits.length()==0) return new ArrayList<>();
        HashMap<Character, Integer> hashMap = new HashMap<>();
        //哈希表填充
        for (int i = 2; i <= 9; i++) {
            if (i == 7 || i == 9) hashMap.put((char) (i + '0'), 4);
            else hashMap.put((char) (i + '0'), 3);
        }

        //储存第一次的结果
        char[] chars = getCharArray(hashMap, digits.charAt(0));
        List<String> result = new ArrayList<>();
        for (char aChar : chars) {
            result.add(Character.toString(aChar));
        }
        //把第一个字符除去
        return combinationsHelper(result, hashMap, digits.substring(1));
    }

    /**
     * 尾递归
     * @return
     */
    private static List<String> combinationsHelper(List<String> list, HashMap<Character, Integer> hashMap, String str) {
        if (str.length() == 0) return list;
        else {
            char[] chars = getCharArray(hashMap, str.charAt(0));
            List<String> L = new ArrayList<>();
            for (String s :
                    list) {
                for (char aChar : chars) {
                    L.add(s + aChar);
                }
            }
            //把第一个字符除去
            return combinationsHelper(L, hashMap, str.substring(1));
        }
    }

    /**
     * ASCII转char
     * @param hashMap
     * @param ch
     * @return
     */
    private static char[] getCharArray(HashMap<Character, Integer> hashMap, char ch) {
        int num = 0, i = 2;
        for (; i < (int) (ch - '0'); i++) {
            num += hashMap.get((char) (i + '0'));
        }
        i = hashMap.get(ch);
        char[] chars = new char[i];
        //ASCII码转换
        for (int j = 0; j < i; j++) {
            chars[j] = (char) ('a' + num + j);
        }
        return chars;
    }
}
```

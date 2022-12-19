这道题可以用双指针来解决 快指针不断往前走 慢指针存不是元音的char
class Solution {
    public String removeVowels(String S) {
        char[] ch = S.toCharArray();
        HashSet<Character> set = new HashSet<>(Arrays.asList('a','o','e','i','u','A','O','E','I','U'));
        int i = 0;
        for(int j = 0; j < ch.length; j++)
        {
            if(!set.contains(ch[j]))
            {
                ch[i] = ch[j];
                i++;
            }
        }
        return new String(ch).substring(0, i);
    }
}
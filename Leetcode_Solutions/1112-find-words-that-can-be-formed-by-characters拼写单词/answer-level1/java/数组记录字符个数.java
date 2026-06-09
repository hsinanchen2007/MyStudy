class Solution {
    public int countCharacters(String[] words, String chars) {
        int len = 0;
        boolean flag = true;
        int[] arr = new int[26];
        for(char tmp : chars.toCharArray()) {
            arr[tmp - 'a']++;
        }
        for(String str: words) {
            char[] charArray = str.toCharArray();
            int[] tmpArr = Arrays.copyOf(arr, arr.length);
            flag = true;
            for(char c : charArray) {
                if(tmpArr[c - 'a'] > 0) {
                    tmpArr[c - 'a']--;
                }else {
                    flag = false;
                    break;
                }
            }
            len += flag?charArray.length : 0;
        }
        return len;
    }
}
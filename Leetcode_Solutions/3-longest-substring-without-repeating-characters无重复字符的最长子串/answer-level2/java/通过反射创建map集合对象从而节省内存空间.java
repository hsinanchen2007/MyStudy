class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), value = 0;
        //反射来创建对象
        Class<HashMap> hashMapClass = HashMap.class;
        HashMap hashMap = null;
        try {
            hashMap = hashMapClass.getConstructor().newInstance();
        } catch (Exception e) {
            e.printStackTrace();
        } 
        for(int i = 0, j = 0; i < n; i++) {
            if (hashMap.containsKey(s.charAt(i))) {
                j = Math.max((int) hashMap.get(s.charAt(i)),j);
            }
            value=Math.max(i-j+1,value);
            hashMap.put(s.charAt(i),i+1);
        }
        return value;
    }
}
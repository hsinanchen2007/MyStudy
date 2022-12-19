全程使用map,最有效的是minSize，如果在长字符串取得了最大值，那么最短字符串出现的次数>=长字符串出现次数

```java
class Solution {
   private boolean checkMaxLetter(String s,int maxLetter){
        Map<Character,Integer> m = new HashMap<>();
        char[] chars=s.toCharArray();
        for(char c:chars){
            m.put(c,m.getOrDefault(c,0)+1);
            if(m.size()>maxLetter) return false;
        }
        return true;
    }
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int max = 0;
        Map<String,Integer> m = new HashMap<>();
        for(int i=0;i<=s.length()-minSize;i++){
            String t = s.substring(i,i+minSize);
            m.put(t,m.getOrDefault(t,0)+1);
        }
        for(String t:m.keySet()){
            if(m.get(t)>max&&checkMaxLetter(t,maxLetters)) max = m.get(t);
        }
        return max;
    }
}
```
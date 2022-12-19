### 解题思路
1. 首先没有好思路，就实现了最暴力的解法。遍历s中每一个p长度串，然后判断是否是异位词。判断方法是使用两个哈希表来存储字母和频次加一点小剪枝。不出意外超时了。
### 代码
```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if(s == null || s.length() == 0 || p == null || p.length() == 0 || s.length() < p.length())
            return new ArrayList();
        Map<Character, Integer> pMap = new HashMap<>();
        Map<Character, Integer> sMap = new HashMap<>();
        for(char c : p.toCharArray()) pMap.put(c, pMap.getOrDefault(c, 0) + 1);
        List<Integer> res = new ArrayList<>();

        int sLength = s.length();
        int pLength = p.length();
        char[] sChar = s.toCharArray();

        for(int i = 0; i <= sLength-pLength; i++){
            sMap.clear();
            for(int j = i; j < i + pLength; j++){
                if(pMap.containsKey(sChar[j]))
                    sMap.put(sChar[j], sMap.getOrDefault(sChar[j], 0) + 1);
                else{
                    i = j;
                    break;
                }
            }
                
            if(sMap.equals(pMap)) res.add(i);
        }
        return res;
    }
}
```
### 解题思路
2. 然后想起用转质数相乘的方法来解决，尝试结果为解答错误。分析原因是乘积数长度越界了。。
### 代码
```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if(s == null || s.length() == 0 || p == null || p.length() == 0 || s.length() < p.length())
            return new ArrayList();
        Map<Character, Integer> wordMap = new HashMap<>();
        int sLength = s.length();
        int pLength = p.length();
        char[] sChar = s.toCharArray();
        List<Integer> res = new ArrayList<>();
        char[] words = new char[]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z'};
        int[] primes = new int[]{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        for(int i = 0; i < words.length; i++) wordMap.put(words[i], primes[i]);


        long pProduct = 1, sProduct = 1;
        for(char c : p.toCharArray()) pProduct *= wordMap.get(c);

        for(int i = 0; i < pLength; i++) 
            sProduct *= wordMap.get(sChar[i]);
        if(sProduct == pProduct) res.add(0);

        for(int i = pLength; i < sLength; i++){
            sProduct /= wordMap.get(sChar[i - pLength]);
            sProduct *= wordMap.get(sChar[i]);
            if(sProduct == pProduct) res.add(i - pLength + 1);
        }
        
        return res;
    }
}
```
### 解题思路
3. 想到质数相乘的方法是，就有点滑动窗口的意思了。因此就将1,2方法进行了合并，即通过使用两个哈希表存储字母和频次，然后维护p长度大小的窗口，逐个删除，添加。。。。直到最后。结果通过，时间在90ms左右。
### 代码
```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if(s == null || s.length() == 0 || p == null || p.length() == 0 || s.length() < p.length())
            return new ArrayList();
        Map<Character, Integer> pMap = new HashMap<>();
        Map<Character, Integer> sMap = new HashMap<>();
        for(char c : p.toCharArray()) pMap.put(c, pMap.getOrDefault(c, 0) + 1);
        List<Integer> res = new ArrayList<>();

        int sLength = s.length();
        int pLength = p.length();
        char[] sChar = s.toCharArray();

        for(int i = 0; i < pLength; i++) sMap.put(sChar[i], sMap.getOrDefault(sChar[i], 0) + 1);
        if(sMap.equals(pMap)) res.add(0);

        for(int i = pLength; i < sLength; i++){
            char delete = sChar[i - pLength];
            if(sMap.get(delete) == 1) sMap.remove(delete);
            else sMap.put(delete, sMap.get(delete) - 1);
            sMap.put(sChar[i], sMap.getOrDefault(sChar[i], 0) + 1);
            if(sMap.equals(pMap)) res.add(i - pLength + 1);
        }
        return res;
    }
}
```
### 解题思路
4. 后来在别人题解中看的使用数组来存储字母和频次，因此替换了哈希表。时间到了7ms。
5. 大神题解的思路非常好，而且是一个通用的方法，值得借鉴。
### 代码
```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if(s == null || s.length() == 0 || p == null || p.length() == 0 || s.length() < p.length())
            return new ArrayList();

        int[] P = new int[26];
        int[] S = new int[26];
        Map<Character, Integer> pMap = new HashMap<>();
        Map<Character, Integer> sMap = new HashMap<>();
        for(char c : p.toCharArray()) P[c-'a'] += 1;
        List<Integer> res = new ArrayList<>();

        int sLength = s.length();
        int pLength = p.length();
        char[] sChar = s.toCharArray();

        for(int i = 0; i < pLength; i++) S[sChar[i]-'a'] += 1;
        if(Arrays.equals(P, S)) res.add(0);

        for(int i = pLength; i < sLength; i++){
            char delete = sChar[i - pLength];
            if(S[delete-'a'] != 0) S[delete-'a'] -= 1;
            S[sChar[i]-'a'] += 1;
            if(Arrays.equals(P, S)) res.add(i - pLength + 1);
        }
        return res;
    }
}
```
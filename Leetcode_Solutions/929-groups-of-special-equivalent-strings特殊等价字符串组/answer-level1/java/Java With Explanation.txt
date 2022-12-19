这题目描述模糊不清。该题的意思是找出整个字符串里面有多少个不同的等价字符串，这个等价定义就是字符串的偶数位可以随便调换位置，奇数位同理。
那么两个字符串等价要满足
- 奇数位对应的字母频数完全相同
- 偶数位对应的字母频数完全相同

那么我们把一个等价组当作一个元素，最后判断有多少个元素即可。
``` java
    public int numSpecialEquivGroups(String[] A) {
         
        Set<String> set = new HashSet<>();
        for (String a : A) {
            
            int[] odd = new int[26];
            int[] even = new int[26];
            
            for (int i = 0; i < a.length(); i++) {
                
                if ((i & 1) == 0)
                    even[a.charAt(i) - 'a']++;
                else 
                    odd[a.charAt(i) - 'a']++;
            }
            set.add(Arrays.toString(odd) + Arrays.toString(even));
        }
        
        return set.size();
    }
```
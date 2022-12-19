![image.png](https://pic.leetcode-cn.com/8fc51ff0feec7fa25b57b3be5aa897e4e5f2eb25be5abd06bc5c50bbea8cfa81-image.png)


首先创建一个长度为26的数组，第0~26项分别保存a~z出现的次数；
后面就很简单了，依次取出每个字符串做减法即可。

```java
class Solution {
    public List<String> commonChars(String[] A) {
        List<String> results = new ArrayList();
        int[] map1 = new int[26]; // 保存最后结果
        int[] map2 = new int[26]; // 用作对比
        
        char[] a0 = A[0].toCharArray();
        for(char c: a0) {
            map1[c - 'a']++;
        }
        for(int i = 1; i < A.length; i++) {
            char[] ai = A[i].toCharArray();
            for(char c : ai) {
                map2[c - 'a']++;
            }
            for(int j = 0; j < 26; j++) {
                if(map1[j] != 0){
                    map1[j] = Math.min(map1[j], map2[j]);
                }
                if(map2[j] != 0) {
                    map2[j] = 0;
                }
            }
        }
        
        // System.out.println(Arrays.toString(map1));
        for(int i = 0; i < 26; i++){
            if(map1[i] == 0) continue;
            
            String s = Character.toString((char) (i + 'a'));
            while(map1[i]-- > 0) {
                results.add(s);
            }
        }
        
        return results;
    }
}
```
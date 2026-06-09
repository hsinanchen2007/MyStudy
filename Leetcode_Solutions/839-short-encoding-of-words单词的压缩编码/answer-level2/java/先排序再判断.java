### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public int minimumLengthEncoding(String[] words) {
   

 Comparator<String> cmp = (s1, s2) -> {
        int N1 = s1.length();
        int N2 = s2.length();
        for (int i = 0; i < Math.min(N1, N2); i++) {
            char c1 = s1.charAt(N1 - 1 - i);
            char c2 = s2.charAt(N2 - 1 - i);
            int c = Character.compare(c1, c2);
            if (c != 0) {
                return c;
            }
        }
        return Integer.compare(N1, N2);
    };
    // 逆序字典序排序    
    Arrays.sort(words, cmp);

int ans = 0;
        int len = words.length;
            if(len == 1)
            {
return words[0].length() +1;
            }
        for(int i = 0;i < len-1;i++)
        {        
     if(words[i+1].contains(words[i]))
     {
continue;
     }
    ans += words[i].length()+1;

        }
        ans += words[len-1].length()+1;;
        return ans;
     
    }


}
```
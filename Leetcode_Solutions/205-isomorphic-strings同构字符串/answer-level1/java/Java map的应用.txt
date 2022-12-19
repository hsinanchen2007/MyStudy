```java
public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length())  return false;
        int[] map1 = new int[256];
        int[] map2 = new int[256];

        for(int i = 0;i<s.length();i++){
            if(map1[s.charAt(i)]==0)
                map1[s.charAt(i)]=i;
            if(map2[t.charAt(i)]==0)
                map2[t.charAt(i)]=i;
            if(map1[s.charAt(i)]!=map2[t.charAt(i)])
                return false;
        }
        return true;
    }
```

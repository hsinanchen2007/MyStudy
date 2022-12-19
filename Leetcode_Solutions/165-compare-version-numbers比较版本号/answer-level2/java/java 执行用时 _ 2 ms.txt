```
public int compareVersion(String version1, String version2) {
        String[] s1 = version1.split("\\.");
        String[] s2 = version2.split("\\.");
        
        int len = Math.max(s1.length,s2.length);
        int i1 = 0;
        int i2 = 0;
        
        for(int i=0;i<len;i++){
            if(s1.length>i && s2.length>i && Integer.valueOf(s1[i])>Integer.valueOf(s2[i])){
                return 1;
            }else if(s1.length>i && s2.length>i && Integer.valueOf(s1[i])<Integer.valueOf(s2[i])){
                return -1;
            }
            if(s1.length>i)
                i1=i1+Integer.valueOf(s1[i]);
            if(s2.length>i)
                i2=i2+Integer.valueOf(s2[i]);
        }
        if(i1>i2)return 1;
        if(i1<i2)return -1;
        return 0;
    }
```

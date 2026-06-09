### 解题思路
1、逐步缩短str2的长度（即产生子串sub），同时与str1和str2对比，是否可被除尽
2、若缩短到最短（空串）仍不能被除尽，则返回空字符串
3、判断能否被除尽：
   不断在长串中取与短串长度对应的子串，只要有一次与短串不相等，则false掉

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(str1==null||str2==null){
            return null;
        }
        if(str1.length()==0||str2.length()==0){
            return "";
        }
        if(str1.length()<str2.length()){
            String temp = str1;
            str1 = str2;
            str2 = temp; 
        }

        int n = str2.length();
        for(int i = n;i>=1;i--){
            String sub = str2.substring(0,i);
            if(handle(str1, sub)&&handle(str2, sub)){
                return sub;
            }
        }

        return "";
    }

    public boolean handle(String str, String sub){
        int len1 = str.length();
        int len2 = sub.length();

        if(len1%len2!=0){
            return false;
        }

        int i = 0;
        int j = len2;
        while(j<=len1){
            String temp = str.substring(i,j);
            if(!temp.equals(sub)){
                return false;
            }
            i+=len2;
            j+=len2;
        }

        return true;
    }
}
```
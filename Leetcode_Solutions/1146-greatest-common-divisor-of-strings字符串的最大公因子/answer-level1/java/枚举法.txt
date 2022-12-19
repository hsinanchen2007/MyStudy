### 解题思路
如果判断字符串被整除，其实只要找到比较短的那个字符串，然后从0-length截取字符串，如果该长度能被str1长度，str2长度，整除，则判断该子字符串是否为公除数，不断的增大字符串的长度，以此判断就能找到最长公共整除串

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        String X = "";
        String shortStr;
        String longStr;
        int shortLength;
        int longLength;
        int length1 = str1.length();
        int length2 = str2.length();
        if(length1 > length2){
            shortStr = str2;
            shortLength = length2;
            longStr = str1;
            longLength = length1;
        }else{
            shortStr = str1;
            shortLength = length1;
            longStr = str2;
            longLength = length2;
        }

        for(int i = 1;i <= shortLength;i++){
           if(shortLength % i == 0 && longLength % i == 0){
               int shortCount = shortLength / i;
               int longCount = longLength / i;
               String baseStr = shortStr.substring(0,i);
               if(shortStr.equals(appendString(baseStr,shortCount)) 
                    && longStr.equals(appendString(baseStr,longCount))){
                    X = baseStr;
                }
           }
        }
        return X;
    }

    public String appendString(String base,int count){
        String str = "";
        for(int i = 0 ; i < count; i ++){
            str += base;
        }
        return str;
    }
}
```
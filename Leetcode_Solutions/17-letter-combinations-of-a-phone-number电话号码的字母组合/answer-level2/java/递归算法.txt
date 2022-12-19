### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> letterCombinations(String digits) {
        char[] arrs = digits.toCharArray();
        String str[] = new String[arrs.length];
        List<String> list  = new ArrayList();
        if("".equals(digits)){
            return list;
        }
        for (int i = 0; i <arrs.length ; i++) {
            switch (arrs[i]){
                case '2':str[i] = "abc";break;
                case '3':str[i] = "def";break;
                case '4':str[i] = "ghi";break;
                case '5':str[i] = "jkl";break;
                case '6':str[i] = "mno";break;
                case '7':str[i] = "qprs";break;
                case '8':str[i] = "tuv";break;
                case '9':str[i] = "wxyz";break;
            }
        }
        list = getStringWithFor(str,0,list,"");
        return list;
    }

    private static List<String> getStringWithFor(String []s, int i, List<String> list, String stemp) {
        if(i<s.length-1){
            for (int j = 0; j < s[i].length() ; j++) {
                list = getStringWithFor(s,i+1,list,stemp+s[i].charAt(j));
            }
        }else {
            for(int j=0;j<s[i].length();j++){
                list.add(stemp+s[i].charAt(j));
            }
        }
        return list;
    }
}
```
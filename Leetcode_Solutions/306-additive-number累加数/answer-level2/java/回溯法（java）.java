### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/e6ba9a6a63f8e36fe7188d6c2e5b8c4a7bcf788a499909153e7a5a4ae0df458e-image.png)

### 代码

```java
class Solution {

    public boolean isAdditiveNumber(String num) {
        HashMap<Integer, List<String[]>> map = new HashMap<>();
        for(int i = 0; i < num.length(); ++i){
            map.put(i, new ArrayList<>());
        }
        List<String[]> r = core(num, num.length() - 1, 0, map);
        if(r.size() > 0){
            for(String[] rr : r){
                if(rr.length >= 3){
                    return true;
                }
            }
            return false;
        }else {
            return false;
        }
    }

    public List<String[]> core(String num, int tail, int ceng, HashMap<Integer, List<String[]>> map){
        for(int i = 0; i < tail; ++i){
            List<String[]> list = null;
            if(map.get(i).size() != 0){
                list = map.get(i);////////////////////////////////
            }else{
                list = core(num, i, ceng + 1, map);
            }
            String b1 = num.substring(i + 1, tail + 1);
            for(String[] s : list){
                if(s.length <= 1){
                    String[] newS = new String[s.length + 1];
                    for(int j = 0; j < s.length; ++j){
                        newS[j] = s[j];
                    }
                    newS[s.length] = num.substring(i + 1, tail + 1);
                    map.get(tail).add(newS);
                    continue;
                }
                String a1 = s[s.length - 2];
                String a2 = s[s.length - 1];
                if(puduan(a1, a2, b1)){
                    String[] newS = new String[s.length + 1];
                    for(int j = 0; j < s.length; ++j){
                        newS[j] = s[j];
                    }
                    newS[s.length] = b1;
                    List<String[]> tempList = map.get(tail);////////////////////
                    tempList.add(newS);
                }
            }
        }
        map.get(tail).add(new String[]{num.substring(0, tail + 1)});
        return map.get(tail);
    }

    public boolean puduan(String a1, String a2, String b1){
        if(a1.equals("") || a2.equals("") || b1.equals("")) return false;
        if(a1.length() != 1 && a1.charAt(0) == '0') return false;
        if(a2.length() != 1 && a2.charAt(0) == '0') return false;
        if(b1.length() != 1 && b1.charAt(0) == '0') return false;
        int carry = 0;
        int lenA1 = a1.length();
        int lenA2 = a2.length();
        int lenB1 = b1.length();
        int maxLen = Math.max(lenA1, lenA2);
        maxLen = Math.max(maxLen, lenB1);
        for(int i = 0; i < maxLen; ++i){
            int aa1 = (lenA1 - 1 - i) >= 0 ? a1.charAt(lenA1 - 1 - i) - '0' : 0;
            int aa2 = (lenA2 - 1 - i) >= 0 ? a2.charAt(lenA2 - 1 - i) - '0' : 0;
            int bb1 = (lenB1 - 1 - i) >= 0 ? b1.charAt(lenB1 - 1 - i) - '0' : 0;
            if(((aa1 + aa2 + carry) % 10) != bb1){
                return false;
            }else{
                carry = (aa1 + aa2 + carry) / 10;
            }
        }
        if(carry != 0) return false;
        return true;
    }
}
```
### 解题思路
![image.png](https://pic.leetcode-cn.com/0262d586b99d206e86033c91534b67cf9f573cc23d0a57c93794a4756fa562b1-image.png)


### 代码

```java
class Solution {
    public boolean isAdditiveNumber(String num) {
        List<List<String>> r = core(num, num.length() - 1, 0);
        if(r.size() > 0){
            for(List<String> rr : r){
                if(rr.size() >= 3){
                    return true;
                }
            }
            return false;
        }else {
            return false;
        }
    }

    public List<List<String>> core(String num, int tail, int ceng){
        List<List<String>> res = new ArrayList<>();
        for(int i = 0; i <= tail - 1; ++i){
            List<List<String>> temp = core(num, i, ceng + 1);
            for(List<String> list : temp){
                if(list.size() <= 1) {
                    list.add(num.substring(i + 1, tail + 1));
                    res.add(list);
                    continue;
                }
                String a1 = list.get(list.size() - 2);
                String a2 = list.get(list.size() - 1);
                String b1 = num.substring(i + 1, tail + 1);
                if(puduan(a1, a2, b1)){
                    list.add(b1);
                    res.add(list);
                }
            }
        }
        List<String> selfStrList = new ArrayList<>();
        selfStrList.add(num.substring(0, tail + 1));
        res.add(selfStrList);
        return res;
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
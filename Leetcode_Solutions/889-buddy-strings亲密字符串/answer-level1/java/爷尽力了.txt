### 解题思路
![QQ截图20200306151834.png](https://pic.leetcode-cn.com/295eaedbbe4fda0cfe298ff25bea9130451657d4cc564fe70a4241df6b464f81-QQ%E6%88%AA%E5%9B%BE20200306151834.png)

哈希都用上了，爷尽力了

### 代码

```java
class Solution {
    public boolean buddyStrings(String A, String B) {
        int length_A=A.length();
            if(length_A!=B.length()){
            return false;
        }

        boolean res=false;
        char[] chars_A=A.toCharArray();
        char[] chars_B=B.toCharArray();
        int temp1=-1;
        int i=0;
        for(;i<length_A;i++){
            if(chars_A[i]==chars_B[i]){
                continue;
            }
            if(temp1==-1) {
                temp1 = i;
                continue;
            }else{
                char temp_c=chars_A[temp1];
                chars_A[temp1]=chars_A[i];
                chars_A[i]=temp_c;
                String temp_s=String.copyValueOf(chars_A);
                if(temp_s.equals(B)){
                    return true;
                }else{
                    return false;
                }

            }

        }

        if(i==length_A){//AB必相同
            Map<Character, Integer> h = new HashMap();
            for(char c:chars_A){
                h.put(c, !h.containsKey(c) ? 1 : h.get(c) + 1);
            }
            for (Character key : h.keySet()) {
                if(h.get(key)!=1){
                    return true;
                }
            }
            return false;
            
        }

        return res;

    }
}
```
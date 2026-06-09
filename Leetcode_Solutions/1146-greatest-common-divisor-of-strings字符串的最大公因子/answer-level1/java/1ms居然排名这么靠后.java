![image.png](https://pic.leetcode-cn.com/89ea791da1b2d17a519fb13f5327f294167b5d26db15380e1749ac39afba8016-image.png)

### 解题思路
感觉写的好混乱
### 代码

```java
class Solution {
    private String min;
    private String max;
    public String gcdOfStrings(String str1, String str2) {
        if(str1.length() > str2.length()){
            max = str1;
            min = str2;
        } else {
            max = str2;
            min = str1;
        }
        if(max.length() == min.length() && max.equals(min)) return min;
        
        int d = min.length();
        if(max.length()%min.length() == 0){
            for(int i = 0; i < max.length()/d - 1; i++){
                if(!max.substring(i*d,(i+1)*d).equals(max.substring((i+1)*d,(i+2)*d))){
                    break;
                }
                if(i == max.length()/d-2){
                    return min;
                }
            }
        }
        if(d < 2) return ""; 
        return match(d/2);
    }
    public String match(int d){
        if(max.length()%d == 0 && min.length()%d == 0){
            int lm = max.length()/d, ln = min.length()/d;
            for(int i = 0; i < lm - 1; i++){
                if(!max.substring(i*d,(i+1)*d).equals(max.substring((i+1)*d,(i+2)*d))){
                    break;
                }
                if((i < ln-1)&&!min.substring(i*d,(i+1)*d).equals(min.substring((i+1)*d,(i+2)*d))){
                    break;
                }
                if(i == lm-2){
                    return min.substring(0,d);
                }
            }
        }
        d--;
        if(d == 0) return "";
        return match(d);
    }
}
```

解法如下：

```
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length() != s2.length()){
            return false;
        }

        int[] temp = new int[256];
        for(int i=0;i<s1.length();i++){
            temp[s1.charAt(i)]++;
        }
        for(int i=0;i<s2.length();i++){
            if(temp[s2.charAt(i)] == 0){
                return false;
            }
            temp[s2.charAt(i)]--;
        }
        return true;
    }
}
```

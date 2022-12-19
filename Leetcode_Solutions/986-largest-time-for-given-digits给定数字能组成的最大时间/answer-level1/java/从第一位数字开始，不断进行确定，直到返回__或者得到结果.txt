    思路：对给定的数字进行判断，根据时间的特点得出每一位数字，不满足条件的直接返回空串。
（没啥技术含量，请见谅）

```
class Solution {
    public String largestTimeFromDigits(int[] A) {
        String ans = "";
        int[] res = new int[10];
        for(int i = 0;i < A.length;i++){
            res[A[i]]++;
        }
        int sum = 0;
        for(int i = 6;i < res.length;i++){
            sum += res[i];
        }
        if(res[0] == 0 && res[1] == 0 && res[2] == 0) return "";
        if(res[2] == 0 && res[1] > 0){
            ans += "1";
            res[1]--;
        }
        else if(res[2] > 0 && (res[0] > 0 || res[1] > 0 || res[2] > 0 || res[3] > 0) && sum < 2) {
            ans += "2";
            res[2]--;    
        }
        else if(res[2] > 0 && res[1] > 0 && sum >= 1){
            ans += "1";
            res[1]--;
        }
        else if(res[0] > 0){
            ans += "0";
            res[0]--;
        }
        if(ans.length() == 0) return "";
        if(ans.charAt(0) != '2'){
            for(int i = 9;i >= 0;i--){
                if(res[i] > 0){
                    ans += String.valueOf(i);
                    res[i]--;
                    break;
                }
            }
        }
        else {
            for(int i = 3;i >= 0;i--){
                if(res[i] != 0){
                    ans += String.valueOf(i);
                    res[i]--;
                    break;
                }
            }
        }
        if(ans.length() == 1) return "";
        ans += ":";
        for(int i = 5;i >= 0;i--){
            if(res[i] != 0){
                ans += String.valueOf(i);
                res[i]--;
            }
        }
        if(ans.length() == 3) return "";
        for(int i = 0;i < res.length;i++){
            if(res[i] != 0) ans += String.valueOf(i);
        }
        return ans;
    }
}
```

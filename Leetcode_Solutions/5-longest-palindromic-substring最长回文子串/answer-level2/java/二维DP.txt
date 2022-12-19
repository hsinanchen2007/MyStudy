### 解题思路

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s.equals("")) return "";
        int N = s.length();
        int ans = 0;
        int ai = 0; int aj = 0;
        int[][] arr = new int[N][N];//记录i到j的最大回文字符串；
        for(int i = 0;i < N;i++){//初始化
            for(int j = 0;j < N;j++){
                arr[i][j] = 0;
            }
        }
        int i = 0; int j = 0;
        while(j < N){
            while(i <= j){
                if(s.charAt(i) == s.charAt(j)){
                    if((j - i) <= 2){
                        arr[i][j] = 1 + j - i;
                        if(arr[i][j] > ans){
                            ans = arr[i][j];
                            ai = i;
                            aj = j;
                        }
                    }else{
                        if(arr[i+1][j-1] > 0){
                            arr[i][j] = arr[i+1][j-1] + 2;
                            if(arr[i][j] > ans){
                                ans = arr[i][j];
                                ai = i;
                                aj = j;
                            }
                        }
                    }
                }
                i++;
            }
            i = 0;
            j++;
        }
        return s.substring(ai, aj + 1);
    }
}
```
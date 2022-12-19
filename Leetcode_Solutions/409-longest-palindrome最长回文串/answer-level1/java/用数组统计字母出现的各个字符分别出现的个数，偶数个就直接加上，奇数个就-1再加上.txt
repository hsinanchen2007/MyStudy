```
public int longestPalindrome(String s) {
         int res = 0;
        int[] sum = new int[100];
        sum[0] = 0;
        char[] str = s.toCharArray();
//统计各字符个数
        for(int i=0;i<str.length;i++){
            sum[str[i]-'A']++;
        }
//偶数直接加 奇数-1再加
        for(int i=0;i<sum.length;i++){
            if(sum[i]>0&&sum[i]%2==0)
                res +=sum[i];
            if(sum[i]>0&&sum[i]%2==1){
                res +=sum[i] - 1;
            }
        }
//res等于S的长度就返回res 否则加一 
        return res==str.length?res:res+1;
        
    }
```

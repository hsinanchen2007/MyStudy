```
public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int[] a = new int[128];
        int j =0;
        int count =0;
        int res = 0;
        for(int i=0;i<s.length();i++){
            if(a[s.charAt(i)]++==0){
                count++;
            }
            while(count>k){
                a[s.charAt(j)]--;
                if(a[s.charAt(j)]==0){
                    count--;
                }
                j++;
            }
            res = Math.max(res,i-j+1);
        }
        return res;
    }
```

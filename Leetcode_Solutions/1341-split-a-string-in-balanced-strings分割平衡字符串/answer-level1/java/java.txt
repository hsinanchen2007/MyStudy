```
public int balancedStringSplit(String s) {
        int count=0;
        int sum=1;
        for (int i=0,j=i+1;j<s.length();j++){
            String flagStr=s.substring(i,i+1);
            String nowStr=s.substring(j,j+1);
            if (nowStr.equals(flagStr))sum++;
            else sum--;

            if (sum==0){
                count++;
            }
        }
        return count;
    }
```

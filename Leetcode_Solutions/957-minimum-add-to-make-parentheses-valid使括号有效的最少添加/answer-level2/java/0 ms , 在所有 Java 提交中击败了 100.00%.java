```
    public int minAddToMakeValid(String S) {
        int left = 0, res = 0;
        for(char ch : S.toCharArray()){
            if(ch == '('){
                left++;
            }else {
                if(left > 0){
                    left--;
                }else {
                    res++;
                }
            }
        }
        return res + left;
    }
```


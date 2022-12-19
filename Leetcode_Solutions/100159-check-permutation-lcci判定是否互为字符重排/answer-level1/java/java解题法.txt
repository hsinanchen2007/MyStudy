```
    public  boolean CheckPermutation(String s1, String s2) {
        char[] temp1=new char[255];
        char[] temp2=new char[255];
        char[] c1=s1.toCharArray();
        char[] c2=s2.toCharArray();
        for (char i:c1){
            temp1[i]++;
        }
        for (char i:c2){
            temp2[i]++;
        }
        for (int i=0;i<temp1.length;i++){
            if (temp1[i]!=temp2[i]) return false;
        }
        return true;
    }
```


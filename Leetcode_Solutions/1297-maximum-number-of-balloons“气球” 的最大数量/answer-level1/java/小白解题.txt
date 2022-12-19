```
    public int maxNumberOfBalloons(String text) {
        int b,a,l,o,n;
        b=a=l=o=n=0;
        int count=0;
        for(int i=0;i<text.length();i++){
            String str=text.substring(i,i+1);
            if(str.equals("b"))b++;
            if(str.equals("a"))a++;
            if(str.equals("l"))l++;
            if(str.equals("o"))o++;
            if(str.equals("n"))n++;
        }
        while(b!=0&&a!=0&&l>=2&&o>=2&&n!=0){
            b--;
            a--;
            l=l-2;
            o=o-2;
            n--;
            count++;
        }
        return count;
    }
```

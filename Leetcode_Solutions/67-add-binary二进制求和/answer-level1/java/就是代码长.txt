```
 public String addBinary(String a, String b) {
        if (a==null && b==null)
            return null;
        else if (a==null)
            return b;
        else if (b==null)
            return a;

        char[] A = a.toCharArray();
        char[] B = b.toCharArray();

        StringBuilder res = new StringBuilder();
        char c='0';
        int i=A.length-1,j=B.length-1;
        for (;i>=0 && j>=0; i--,j--){
            if (A[i]=='1' && B[j]=='1'){
                res.insert(0,c);
                c='1';
            }else if(A[i]=='1' || B[j]=='1'){
                if (c=='0'){
                    res.insert(0,'1');
                }else {
                    //c='1'
                    res.insert(0,'0');
                }
            }else{
                res.insert(0,c);
                c='0';
            }
            //System.out.println("temp: "+res.toString()+";c="+c);
        }

        if (i<0 && j<0){
            if (c=='1'){
                res.insert(0,'1');
                c='0';
            }

        }else if (i>=0 || j>=0){
            //A
            if (j>=0){
                i=j;
                A=B;
            }
            while (i>=0){
                if (A[i]=='1'&& c=='1'){
                    res.insert(0,'0');
                    c='1';
                }else if (A[i]=='1' || c=='1'){
                    res.insert(0,'1');
                    c='0';
                }else{
                    res.insert(0,'0');
                }
                i--;
            }
        }

        if (c=='1')
            res.insert(0,'1');

        return res.toString();

    }
```

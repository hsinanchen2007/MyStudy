```
class Solution {
    public String addBinary(String a, String b) {
        int i = a.length() - 1;
        int j = b.length() - 1;

        StringBuilder res = new StringBuilder();

        int carry=0;
        while(i>=0 || j>=0){
            int sum=carry;
            if(i>=0) {sum+= a.charAt(i)-'0'; i--;}
            if(j>=0) {sum+= b.charAt(j)-'0';j--;}
            carry=sum/2;
            sum%=2;
            res.insert(0,sum);
        }
        if(carry==1){
            res.insert(0,1);
        }
        return res.toString();

    }
}
```

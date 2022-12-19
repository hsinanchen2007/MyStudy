```
class Solution {
    public String addBinary(String a, String b) {
        if(a.length()==0||b.length()==0) return a+b;
        int i = a.length()-1,j = b.length()-1;
        int carry = 0;
        StringBuilder res = new StringBuilder();
        while(i >= 0 || j >= 0){
            int ac = i>=0?(a.charAt(i) - '0'):0;
            int bc = j>=0?(b.charAt(j) - '0'):0;
            int sum = ac + bc + carry;
            if(sum>1){
                res.append(sum%2);
                carry = sum/2;
            }else{
                res.append(sum);
                carry = 0;
            }
            i--;
            j--;
        }
        if(carry>0){
            res.append('1');
        }
        return res.reverse().toString();

    }
}
```

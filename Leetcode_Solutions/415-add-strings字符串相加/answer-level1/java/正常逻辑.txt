```
class Solution {
    public String addStrings(String num1, String num2) {
        int l1=num1.length();
        int l2=num2.length();
        int m=0;
        StringBuilder sb=new StringBuilder();
        while(l1>0||l2>0){
            int v1=l1>0?num1.charAt(l1-1)-'0':0;
            int v2=l2>0?num2.charAt(l2-1)-'0':0;
            int sum=v1+v2+m;
            m=sum/10;
            sb.append(sum%10);
            l1--;
            l2--;
        }
        if(m>0){
            sb.append('1');
        }
        return sb.reverse().toString();
    }
}
```

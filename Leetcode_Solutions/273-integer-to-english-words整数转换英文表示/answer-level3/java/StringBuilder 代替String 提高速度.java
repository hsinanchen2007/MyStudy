```class Solution {
    String[] low = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    String[] mid = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    String[] high = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    public String numberToWords(int num) {
        if(num==0)return "Zero";
        int part1=num%1000;
        num=num/1000;
        int part2=num%1000;
        num=num/1000;
        int part3=num%1000;
        int part4=num/1000;
        StringBuilder res=new StringBuilder();
        if(part4!=0){
            res.append(builds(part4)).append(" ").append("Billion");
        }
        if(part3!=0){
            res.append(" ").append(builds(part3)).append(" ").append("Million");
        }
        if(part2!=0){
            res.append(" ").append(builds(part2)).append(" ").append("Thousand");
        }if(part1!=0){
            res.append(" ").append(builds(part1));
        }
        return res.toString().trim();
    }
    public String builds(int num){
        int a=num%10;
        num=num/10;
        int b=num%10;
        int c=num/10;
        StringBuilder res=new StringBuilder();
        if(c!=0){
           res.append(low[c]).append(" ").append("Hundred");
        }
        if(b==1){
             res.append(" ").append(mid[a]);
        }else if(b==0){
             res.append(" ").append(low[a]);
        }else{
           res.append(" ").append(high[b]).append(" ").append(low[a]);
        }
        return res.toString().trim();
    }
}
```

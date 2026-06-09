统计各部分，拼接起来。
```
class Solution {
    public String numberToWords(int num) {
        if(num == 0)
            return "Zero";
        List<String> res = new ArrayList<>();
        int hundred = 0;
        int thousand = 0;
        int million = 0;
        int billion = 0;
        if(num < 0){
            res.add("Negative");
            num = -num;    
        }
        if(num > 0){
            hundred = num % 1000;
            num /= 1000;
            if(num > 0){
                thousand = num % 1000;
                num /= 1000;
                if(num > 0){
                    million = num % 1000;
                    num /= 1000;
                    if(num > 0){
                        billion = num % 1000;
                    }
                }
            }
        }
        if(billion > 0){
            for(String str:change(billion))
                res.add(str);
            res.add("Billion");
        }
        if(million > 0){
            for(String str:change(million))
                res.add(str);
            res.add("Million");
        }
        if(thousand > 0){
            for(String str:change(thousand))
                res.add(str);
            res.add("Thousand");
        }
        if(hundred > 0){
            for(String str:change(hundred))
                res.add(str);
        }
        StringBuilder ans = new StringBuilder();
        for(String s:res){
            if(ans.length() == 0)
                ans.append(s);
            else{
                ans.append(" " + s);
            }
        }
        return ans.toString();
    }
    private LinkedList<String> change(int num){
        LinkedList<String> list = new LinkedList<>();
        int n = num % 100;
        if(0 < n && n < 20){
            list.addFirst(num0_19[n]);
        }else if(n >= 20){
            int m = n % 10;
            int mm = n / 10;
            if(m > 0)
                list.addFirst(num0_19[m]);
            list.addFirst(num0_90[mm]);
        }
        if(num >= 100){
            list.addFirst("Hundred");
            list.addFirst(num0_19[num / 100]);
        }
        return list;
    }
    private String[] num0_19 = new String[]{ "Zero","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
    private String[] num0_90 = new String[]{ "Zero","Ten","Twenty","Thirty", "Forty", "Fifty", "Sixty",  "Seventy", "Eighty", "Ninety" };
}
```

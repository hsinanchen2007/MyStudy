```
    public boolean isAnagram(String s, String t) {
        return Math.abs(sumChar(s) - sumChar(t)) < 0.0001;
    }
    
    //查看数字加起来起来是否一样 抄别人的。
    public double sumChar(String s){
        double sum = 0;
        char[] cs = s.toCharArray();
        for(char c : cs){
            sum += Math.pow((int)c,0.5);
        }
        return sum;
    }
```

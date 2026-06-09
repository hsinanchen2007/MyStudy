计算两个数组所有char的合的差值，就是不同的那一个char
    public char findTheDifference(String s, String t) {
        char[] sChars = s.toCharArray();
        char[] tChars = t.toCharArray();
        int different  = sum(tChars) - sum(sChars);
        return (char) different;
    }

    private int sum(char[] sChars){
        int sum = 0;
        for(int i=0;i<sChars.length;i++){
            sum += sChars[i];
        }
        return sum;
    }
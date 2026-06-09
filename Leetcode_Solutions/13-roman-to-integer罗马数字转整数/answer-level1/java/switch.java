class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        for(int i =0; i< s.length(); i++) {
            char ch = s.charAt(i);
            switch(ch) {
                case 'I':
                sum += 1;
                System.out.println("1");
                break;

                case 'V':
                if(i > 0 && s.charAt(i-1) =='I') {
                    sum += 5 - 1*2;
                } else {
                    sum += 5;
                }
                break;

                case 'X':
                if(i > 0 && s.charAt(i-1) =='I') {
                    sum += 10 - 1*2;
                } else {
                    sum += 10;
                }
                break;

                case 'L':
                if(i > 0 && s.charAt(i-1) =='X') {
                    sum += 50 - 10*2;
                } else {
                    sum += 50;
                }
                break;

                case 'C':
                if(i > 0 && s.charAt(i-1) =='X') {
                    sum += 100 - 10*2;
                } else {
                    sum += 100;
                }
                break;

                case 'D':
                if(i > 0 && s.charAt(i-1) =='C') {
                    sum += 500 - 100*2;
                } else {
                    sum += 500;
                }
                break;

                case 'M':
                if(i > 0 && s.charAt(i-1) =='C') {
                    sum += 1000 - 100*2;
                } else {
                    sum += 1000;
                }
                break;
            }
        }
        return sum;
    }
}
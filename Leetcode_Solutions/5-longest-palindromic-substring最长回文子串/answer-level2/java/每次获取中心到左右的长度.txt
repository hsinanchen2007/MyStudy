class Solution {
        public String longestPalindrome(String s) {
            if(s==null || s.length()<=1){return s;}
            int[] max = new int[]{0,0};
           
            for(int  i =0; i < s.length()-1;i++){

                int[] p1=  palindrome(s,i-1,i+1);
                if( p1[1]-p1[0] > max[1]-max[0]){
                    max = p1;
                }
                int[] p2=  palindrome(s,i,i+1);
                if( p2[1]-p2[0] > max[1]-max[0]){
                    max = p2;
                }
            }

            return s.substring(max[0],max[1]);


        }

        public int[]  palindrome(String s ,int m,int n){
            while(m >=0 && n <s.length()){
                if(s.charAt(m) == s.charAt(n)){
                    m--;
                    n++;
                }else{
                    break;
                }
            }
            return  new int[]{m+1,n};
        }
    }
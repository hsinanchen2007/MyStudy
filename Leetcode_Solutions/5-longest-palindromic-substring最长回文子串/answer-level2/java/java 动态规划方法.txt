        public String longestPalindrome(String s) {
            int N=s.length();
            int i,j=0;
            int maxlength=-1;
            String longstring="";
            boolean[][] p=new boolean[N+1][N+1];
            for(int q=0;q<=N;q++){
                for(int d=0;d<=N;d++){
                    p[q][d]=true;
                }
            }
            for(int k=1;k<N+1;k++){
                j=k;
                for(i=1;i<N-k+2;i++)
                {
                    if(i==j){
                        p[i][j]=true;
                    }
                    else {

                        if (p[i + 1][j -1] == true && s.charAt(i-1) == s.charAt(j-1)) {
                            p[i][j] = true;
                        }

                        else
                            p[i][j] = false;
                    }
                    j++;
                }

            }
            if (N==1){
                return s;
            }
            for(i=1;i<N+1;i++){
                for(j=i;j<N+1;j++){
                    if (p[i][j]==true&&(j-i)>=maxlength){
                        maxlength=j-i;
                        longstring=s.substring(i-1,j);
                    }
                }
            }
            return longstring;
        }
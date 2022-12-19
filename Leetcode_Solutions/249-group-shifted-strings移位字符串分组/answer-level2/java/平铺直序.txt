class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        int [] dp = new int [strings.length];        
        List<List<String>> lis = new ArrayList<>();

        int i,j;
        for(i=0;i<strings.length;i++){
            dp[i]=-1;
        }
        for(i=0;i<strings.length;i++){
            List<String> ll =new ArrayList<>();
          
            if(dp[i]!=-1){
                continue;
            }
            ll.add(strings[i]);
            for(j=i+1;j<strings.length;j++){

                if( dp[j]==-1 && strings[i].length()==strings[j].length()){
                    int num = jian(strings[i].charAt(0),strings[j].charAt(0));
                    int flag = 0 ;
                    for(int k=1;k<strings[i].length();k++){
                        if(num!=jian(strings[i].charAt(k),strings[j].charAt(k))){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        dp[i]=i;
                        dp[j]=i;
                        ll.add(strings[j]);
                    }
                }

            }
            lis.add(ll);
        }
      
        return lis ;
        
    }

    private int jian(char a,char b){
        int i,j;
        if(b>a){
            return b-a;
        }
        else if (b==a){
            return 0;
        }
        else{
           return 26-(a-b);
        }

    }
}
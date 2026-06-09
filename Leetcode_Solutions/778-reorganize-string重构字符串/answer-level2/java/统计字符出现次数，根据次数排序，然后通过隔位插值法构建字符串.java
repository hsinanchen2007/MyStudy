
```
class Solution {
    public String reorganizeString(String S) {
        //只包含小写字符
        if(S==null) return null;
        if(S=="") return "";
        int[] countChar=new int[26];
        for(int i=0;i<S.length();i++){
            int t=S.charAt(i)-'a';
            // System.out.print(S.charAt(i)+" ");
            // System.out.println(S.charAt(i)-'a');
            countChar[t]++;
        }
        int[][] sortCount=new int[26][2];
        for(int i=0;i<26;i++){
            sortCount[i][0]=i;
            sortCount[i][1]=countChar[i];
        }
        Arrays.sort(sortCount,new Comparator<int[]>(){
            public int compare(int[] a,int[] b){
                return b[1]-a[1];
            }
        });
        int n=S.length();
        if(n%2==1 && sortCount[0][1]>n/2+1) return "";
        if(n%2==0 && sortCount[0][1]>n/2) return "";
        char[] temp=new char[n];
        int cur=0;
        int pre=1;
        int i=0;
        char[] alpha={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(;i<26;i++){
            if(cur>n-1) break;
            for(int j=0;j<sortCount[i][1];j++){
                if(cur<=n-1){
                    temp[cur]=alpha[sortCount[i][0]];
                    cur+=2;
                }else{
                    temp[pre]=alpha[sortCount[i][0]];
                    pre+=2;
                }
            }
        }
        for(;i<26;i++){
            
            for(int j=0;j<sortCount[i][1];j++){
                    
                    temp[pre]=alpha[sortCount[i][0]];
                    pre+=2;
          
            }
        }
        return new String(temp);
    }
}
```

class Solution {
    public static int kSimilarity(String A, String B) {
        int rs=0;
        if(A.equals(B)){
            return 0;
        }
        ArrayDeque<String>q=new ArrayDeque<>();
        ArrayDeque<Integer>p=new ArrayDeque<>();
        int i=0;
        int j;
        q.addLast(A);
        p.addLast(0);
        while(!q.isEmpty()){
            String s=q.removeFirst();
            rs=p.removeFirst();
            if(s.equals(B)){
                break;
            }
            for(j=0;j<B.length();j++){
                if(s.charAt(j)!=B.charAt(j)){
                    break;
                }
            }
            for(int k=j+1;k<s.length();k++){
                if(s.charAt(k)==B.charAt(j)){
                    q.addLast(s.substring(0,j)+s.charAt(k)+s.substring(j+1,k)+s.charAt(j)+s.substring(k+1));
                    p.addLast(rs+1);
                }
            }

        }
        return rs;
    }
}
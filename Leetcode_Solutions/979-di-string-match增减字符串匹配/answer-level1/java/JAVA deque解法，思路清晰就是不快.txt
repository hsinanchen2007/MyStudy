 public int[] diStringMatch(String S) {
        
        int n=S.length();
       ArrayDeque<Integer> queue = new ArrayDeque();
         int[] result=new int[n+1];
        for(int i=0;i<n+1;i++){
            queue.add(i);
        }
        char schar []=S.toCharArray();
       for(int i = 0;i<schar.length;i++){
           if(schar[i]=='I'){
               result[i]=queue.pollFirst();
           }
           if(schar[i]=='D'){
               result[i]=queue.pollLast();
           }
       }
        result[n]=queue.poll();
        return result;
   }
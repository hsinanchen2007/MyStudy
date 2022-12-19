class Solution {
    public String multiply(String num1, String num2) {
        
        Map<String,Integer> map=new HashMap<>();
        
        map.put("0",0);
        map.put("1",1);
        map.put("2",2);
        map.put("3",3);
        map.put("4",4);
        map.put("5",5);
        map.put("6",6);
        map.put("7",7);
        map.put("8",8);
        map.put("9",9);

        if(num1==null||num2==null){
            return null;
        }
        
        if(num1.charAt(0)=='0'||num2.charAt(0)=='0'){
            return "0";
        }
        
        Stack<List<String>> st=new Stack<>();
        
        for(int i=0;i<num2.length();i++){
            
            List<String> li=new LinkedList<>();
            int c=0;
            
            for(int j=num1.length()-1;j>=0;j--){
                int kk=map.get(Character.toString(num2.charAt(i)))*map.get(Character.toString(num1.charAt(j)));
                kk=kk+c;
                c=kk/10;
                kk=kk%10;
                li.add(Integer.toString(kk));
            }
            if(c>0){
                li.add(Integer.toString(c));
            }
                
            st.push(li);
            
        }
        
        int i=0;
        int[] res=new int[220];
        
        
        for(int xyz=0;xyz<220;xyz++){
            res[xyz]=0;
        }
        
        
             
        while(!st.isEmpty()){
         
            
            Iterator it=st.pop().iterator();
            
            
            int j=i;
            int jj=0;
            
            while(it.hasNext()){
                
                res[j]=res[j]+map.get(it.next())+jj;
                jj=res[j]/10;
                res[j]=res[j]%10;
                j++;
            }
                
            
            
           if(st.isEmpty()){
              if(jj>0){
                  res[j]+=jj;
                 for(int xyz=j+1;xyz<220;xyz++){
                    res[xyz]=-1;
                 }
               }
               else{
                 for(int xyz=j;xyz<220;xyz++){
                    res[xyz]=-1;
                 }
               }
            
            }
            else{
                
            if(jj>0){
                res[j]+=jj;
                
                
            }
                 i++; 
            }
              
        }
        
        int sta=0;
        
        StringBuilder sb=new StringBuilder();
        
        while(res[sta]!=-1){
            sb.insert(0,res[sta]);
            sta++;
        }
            
        return sb.toString();   
    }
}
![6OE{LA~~7`2LLGZJYFAI\[WI.png](https://pic.leetcode-cn.com/23c67f8c0aabcf91a22ceb106699f5047fd3f7916cbb2f722d7baa5b1275100a-6OE%7BLA~~7%602LLGZJYFAI%5BWI.png)


    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> list=new ArrayList<>();
        Map<String,Integer> map=new HashMap<>();
          Integer a =new Integer(-1);
        StringBuilder build=new StringBuilder("");
        String [] fen=new String[2];
        for(int i=0;i<cpdomains.length;i++){
            fen=cpdomains[i].split(" ");
           a=Integer.parseInt(fen[0]);
           
           String b[]=fen[1].split("\\.");
            for(int j=b.length-1;j>=0;j--){
                if(j==b.length-1)
                build.insert(0,b[j]);
                else
                build.insert(0,b[j]+".");
                
                 map.put(build.toString(),map.getOrDefault(build.toString(),0)+a);
            }
            build.replace(0,build.length(),"");
        }
        
        
        for(Map.Entry<String, Integer> entry : map.entrySet()){ 
        list.add(entry.getValue().toString()+" "+entry.getKey());
        }
        return list;
        
    }


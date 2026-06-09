用map记录访问的结果,如果已存在则将访问次数相加,如果不存在则加入,主要利用map的key值不可重复,如果添加已存在的key就会把之前其对应的value进行替换
```
  public static List<String> subdomainVisits(String[] cpdomains) {
//        存放各种域名访问次数的map
        Map<String,Integer> map = new HashMap<String,Integer>();
        for(String cpdomain : cpdomains){
            if(!cpdomain.contains(" ")){
                continue;
            }
            String[] split = cpdomain.split(" ");
            int count = Integer.parseInt(split[0]);
            String[] yuming = subYuMing(split[1]);
            for (String s : yuming){
                if (map.containsKey(s)){
                    map.put(s,map.get(s)+count);
                }else{
                    map.put(s,count);
                }
            }


        }
        Set<Map.Entry<String, Integer>> entries = map.entrySet();
        List<String> list = new ArrayList<String>();
        for (Map.Entry<String, Integer> entry : entries){
            list.add(entry.getValue()+" "+entry.getKey());
        }
        return list;
    }

    private static String[] subYuMing(String yuming) {
        System.out.println(yuming);
        String[] split = yuming.split("\\.");
        System.out.println(split[0]);
        if(split.length==1){
            return split;
        }
        for(int i=0; i<split.length; i++){
            if(i==split.length-1){break;}
            for(int j = i+1; j<split.length; j++){
                split[i]+="."+split[j];
            }
        }
        return split;
    }
```

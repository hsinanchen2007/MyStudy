/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/12
 *
 * 解题思路: hashMap 的使用
 *
 */
```
public List<String> subdomainVisits(String[] cpdomains) {
    HashMap<String,Integer> hashMap = new HashMap<>();
    List<String> list = new ArrayList<>();

        String[] t = null;
        String[] t2 = null;
        String t3 = null;
        int sum  = 0;
    for(int i = 0;i < cpdomains.length;i++){
        t = cpdomains[i].split(" ");
        t2 = t[1].split("\\.");
        t3 = t2[t2.length - 1];
        sum = Integer.valueOf(t[0]);
        for(int j = t2.length - 2;j >= 0;j--){
            hashMap.put(t3,hashMap.getOrDefault(t3,0) + sum);
            t3 = t2[j] + "." + t3;
        }
        hashMap.put(t3,hashMap.getOrDefault(t3,0) + sum);


//            if(t2.length == 3){
//                hashMap.put(t2[2],hashMap.getOrDefault(t2[2],0) + Integer.valueOf(t[0]));
//                hashMap.put(t2[1]+"."+t2[2],hashMap.getOrDefault(t2[1]+"."+t2[2],0) + Integer.valueOf(t[0]));
//                hashMap.put(t2[0]+"."+t2[1]+"."+t2[2],hashMap.getOrDefault(t2[0]+"."+t2[1]+"."+t2[2],0) + Integer.valueOf(t[0]));
//            }else{
//                hashMap.put(t2[1],hashMap.getOrDefault(t2[1],0) + Integer.valueOf(t[0]));
//                hashMap.put(t2[0]+"."+t2[1],hashMap.getOrDefault(t2[0]+"."+t2[1],0) + Integer.valueOf(t[0]));
//            }
    }

    for(String s : hashMap.keySet()){
        list.add(hashMap.get(s) + " " + s);
    }
    return list;
}
```
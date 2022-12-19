```
// //利用LinkHashMap的有序性
// import java.util.HashMap;
// class Solution {
//     public int firstUniqChar(String s) {
//         Map<Character,Integer> map=new HashMap<Character,Integer>();
//         for(int i=0;i<s.length();i++){
//             if(map.containsKey(s.charAt(i))){
//                 map.put(s.charAt(i),map.get(s.charAt(i))+1);
//             }else{
//                 map.put(s.charAt(i),1);
//             }
//         }
//            for(int i=0;i<s.length();i++) {
//                if(map.get(s.charAt(i))==1){
//                    return i;
//                }
//         }
//         return -1;
//     }
// }

class Solution {
     public int firstUniqChar(String s){
         //数int组
         int[] ch=new int[128];
         int length=s.length();
         for(int i=0;i<length;i++){
             ch[s.charAt(i)]++;
         }
        for(int i=0;i<length;i++){
             if(ch[s.charAt(i)]==1){
                 return i;
             }
         }
         return -1;
     }
}
```


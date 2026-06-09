一开始超时，然后内存超限。参考了大家的思路改进了下。。总结为，自己对List的使用还是不熟练。
一开始用的List<List<String>>来进行手动合并，每次判断都要全部扫描一遍，合并的时候还重新生成一个大的List赋值进去；（超时）
然后用两个map相互指，想要节约扫描的时间，然而超出了内存的限制；（超内存）
没想到去用List的地址，多个名字可以指向同一个List的地址，就不用自己去合并两个list了，空间和时间就节约下来了。
写完这个题对List的使用有点收获
![image.png](https://pic.leetcode-cn.com/6bd21228a76c2ddeeccf4fca664a457a397c4b9488ed06db96e791b27561d128-image.png)

```
class Solution {
   public static String[] trulyMostPopular(String[] names, String[] synonyms) {
        HashMap<String,Integer> map = new HashMap<>();
        HashMap<String,List<String>> nameMap = new HashMap<>();
        //System.out.println(totalCount);
        for(String word : names){
            String name = word.split("\\(")[0]; 
            List<String> temp = new ArrayList<>();
            temp.add(name);
            nameMap.put(name,temp);
            int count = Integer.valueOf(word.split("\\(")[1].split("\\)")[0]);
            if(map.containsKey(name)){
                map.put(name,map.get(name)+count);
            }else{
                map.put(name,count);
            }
        }
        //System.out.println(map);
        // List<List<String>> namesGroup = new ArrayList<>();
        //合并方案（改进重点）
        Comparator<String> comp = new Comparator<String>() {
            public int compare(String s1, String s2) {
            return s1.compareTo(s2);
            }
        };
        for(String namePair : synonyms){
            String[] twoName = namePair.split(",");
            String name1 = twoName[0].substring(1,twoName[0].length());
            String name2 = twoName[1].substring(0,twoName[1].length()-1);
            if(!nameMap.containsKey(name1) || !nameMap.containsKey(name2)) continue;
            if(!nameMap.get(name1).equals(nameMap.get(name2))){
                
                nameMap.get(name1).addAll(nameMap.get(name2));
                Collections.sort(nameMap.get(name1),comp);
                for(String name : nameMap.get(name2)){
                    nameMap.put(name,nameMap.get(name1));
                }
            }
        }
        //结果输出，有点傻傻的。。。
        HashMap<String,Integer> resultMap = new HashMap<>();
        List<String> result = new ArrayList<>();
        for(String name : nameMap.keySet()){
            int count = 0;
            if(resultMap.containsKey(nameMap.get(name).get(0))) continue;
            for(String temp:nameMap.get(name)){
                if(map.containsKey(temp)) count+=map.get(temp);
                
            }
            resultMap.put(nameMap.get(name).get(0),count);
            result.add(nameMap.get(name).get(0)+"("+String.valueOf(count)+")");
        }

        String[] finalResult = new String[result.size()];
        for(int i = 0 ; i < result.size();i++){
            finalResult[i] = result.get(i);
        }
        return finalResult;


  }
}
```

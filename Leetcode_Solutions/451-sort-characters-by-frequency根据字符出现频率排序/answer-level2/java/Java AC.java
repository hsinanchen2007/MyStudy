
### 代码

```java
class Solution {
    public static String frequencySort(String s) {
        HashMap<Character, Integer> map = new HashMap<>(); //hashmap统计字符出现频率
        for(int i=0;i<s.length();i++){
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0)+1);
        }

        Nod[] arr = new  Nod[map.size()];
        int i=0;
        for(Map.Entry entry: map.entrySet()){ 
            arr[i++] = new Nod((char)entry.getKey(), (int)entry.getValue());
        }
        Arrays.sort(arr, new Comparator<Nod>() { //根据出现频率排序
            @Override
            public int compare(Nod o1, Nod o2) {
                return o2.freq-o1.freq;
            }
        });

        StringBuilder sb = new StringBuilder(); //组装成输出
        for(Nod nod : arr){
            for(int j=0;j<nod.freq;j++){
                sb.append(nod.c);
            }
        }
        return sb.toString();
    }

}

class Nod{
    char c;
    int freq;
    public Nod(char c, int frep){
        this.c =c;
        this.freq=frep;
    }
}
```
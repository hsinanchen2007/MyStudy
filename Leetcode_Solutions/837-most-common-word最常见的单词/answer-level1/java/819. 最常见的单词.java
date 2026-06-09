
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/12
 *
 * 解题思路: 两种思路 一种是对单个字符进行扫描直接进行判断  另一种依据符号进行正则切分生成单词在进行判定
 *
 * 注意：正则速度较慢 String.split("[\\s|!|?|\\'|,|;|.]")   String.replace("[\\s|!|?|\\'|,|;|.]")
 *
 */
```
public String mostCommonWord(String paragraph, String[] banned) {
    HashSet<String> hashSet = new HashSet<>();
    HashMap<String,Integer> hashMap = new HashMap<>();

    for(int i = 0;i < banned.length;i++){
        hashSet.add(banned[i]);
    }

    char[] p = paragraph.toCharArray();
    StringBuilder sb = new StringBuilder();
    for(int i = 0;i < p.length;i++){
        //!?',;.
        if(p[i] == ' ' || p[i] == '!' || p[i] == '?' || p[i] == '\'' || p[i] == ',' || p[i] == ';' || p[i] == '.'|| i == p.length-1){
            String temp = sb.toString().toLowerCase();
            if(sb.length() != 0 && !hashSet.contains(temp)){
                hashMap.put(temp,hashMap.getOrDefault(temp,0)+1);
            }
            sb.delete(0,sb.length());
            continue;
        }
        sb.append(p[i]);
    }

    String res = "";
    int res_sum = 0;
    for(String s:hashMap.keySet()){
        if(hashMap.get(s) >= res_sum){
            res = s;
            res_sum = hashMap.get(s);
        }
    }

    return res;
}

public String mostCommonWord2(String paragraph, String[] banned) {
    HashSet<String> hashSet = new HashSet<>();
    HashMap<String,Integer> hashMap = new HashMap<>();

    for(int i = 0;i < banned.length;i++){
        hashSet.add(banned[i]);
    }

    String[] words = paragraph.split("[\\s|!|?|\\'|,|;|.]");
    String temp = "";
    for(int i = 0;i < words.length;i++){
        temp = words[i].toLowerCase();
        if(temp.length() != 0 && !hashSet.contains(temp)){
            hashMap.put(temp,hashMap.getOrDefault(temp,0)+1);
        }
    }

    String res = "";
    int res_sum = 0;
    for(String s:hashMap.keySet()){
        if(hashMap.get(s) >= res_sum){
            res = s;
            res_sum = hashMap.get(s);
        }
    }

    return res;
}
```
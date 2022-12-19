思路：借助HashMap，域名为键，访问次数为值，先按空格分隔原始字符串，得到原始域名和访问次数，然后对原始域名按'逗号分割，得到域名分组，拼接域名分组，得到所有域名和相应的访问次数，将所有域名和访问次数都put到HashMap中，最后遍历HashMap，拼接出答案字符串即可。

```processing
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> ans = new ArrayList<>();
        Map<String,Integer> map = new HashMap<>();
        
        for (String s : cpdomains) {
            // 分割原始字符串，得到原始域名和访问次数
            String split[] = s.split(" ");
            int times = Integer.valueOf(split[0]);
            String domain = split[1];
            // 将原始域名塞入map
            put(map,domain,times);
            
            // 分割出域名组
            split = domain.split("\\.");

            // 按域名组情况处理
            if (split.length == 2) {
                // 此时只需处理顶级域名，原始域名上面已经塞入map了
                put(map,split[1],times);
            } else {
                // 此时存在多级域名，需拼接
                // 先处理顶级域名
                put(map,split[split.length - 1],times);
                // 拼接出多级域名，都塞入map
                for (int i = 1;i < split.length - 1;i++) {
                    StringBuilder key = new StringBuilder(split[i]);
                    for (int j = i + 1;j < split.length;j++) {
                        key.append('.');
                        key.append(split[j]);
                    }
                    put(map,key.toString(),times);
                }
            }
        }
        
        for (String domain : map.keySet()) {
            ans.add(map.get(domain) + " " + domain);
        }
        
        return ans;
    }
    
    private void put(Map<String,Integer> map,String key,Integer val) {
        if (map.containsKey(key)) {
            map.put(key,map.get(key) + val);
        } else {
            map.put(key,val);
        }
    }
}
```

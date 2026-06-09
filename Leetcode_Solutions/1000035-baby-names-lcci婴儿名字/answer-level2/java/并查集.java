### 解题思路
使用两个Map
1. 一个存储婴儿的名字与出现的次数
2. 另一个存储相同婴儿名字的映射关系

### 代码

```java
class Solution {
    public String[] trulyMostPopular(String[] names, String[] synonyms) {
        Map<String,String> parents = new HashMap<>();
        Map<String,Integer> map = new HashMap<>();
        for (int i = 0; i < names.length; i++) {
            int mid = names[i].indexOf("(");
            String name = names[i].substring(0,mid);
            int num = Integer.parseInt(names[i].substring(mid + 1, names[i].length() - 1));
            map.put(name,num);
            parents.put(name,name);
        }
        for (int i = 0; i < synonyms.length; i++) {
            int mid = synonyms[i].indexOf(",");
            String left = synonyms[i].substring(1, mid);
            if (!map.containsKey(left)){
                map.put(left,0);
                parents.put(left,left);
            }
            String right = synonyms[i].substring(mid + 1, synonyms[i].length() - 1);
            if (!map.containsKey(right)){
                map.put(right,0);
                parents.put(right,right);
            }
            nameJoinName(parents,map,left,right);
        }
        List<String> res = new ArrayList<>();
        Iterator<Map.Entry<String, Integer>> iterator = map.entrySet().iterator();
        while (iterator.hasNext()){
            Map.Entry<String, Integer> entry = iterator.next();
            if (parents.get(entry.getKey()).equals(entry.getKey())){
                StringBuilder sb = new StringBuilder();
                sb.append(entry.getKey()).append("(").append(entry.getValue()).append(")");
                res.add(sb.toString());
            }
        }
        String[] strings = res.toArray(new String[0]);
        return strings;
    }

    private String findNameParent(Map<String,String> parent,String str){
        String s = parent.get(str);
        if (s.equals(str))
            return str;
        return findNameParent(parent,s);
    }

    private void nameJoinName(Map<String,String> parent,Map<String,Integer> map,String left,String right){
        String parent1 = findNameParent(parent, left);
        String parent2 = findNameParent(parent, right);
        if (!parent1.equals(parent2)){
            if (parent1.compareTo(parent2) < 0){
                parent.put(parent2,parent1);
                map.put(parent1,map.get(parent1) + map.get(parent2));
            }
            else{
                parent.put(parent1,parent2);
                map.put(parent2,map.get(parent1) + map.get(parent2));
            }
        }
    }
}
```
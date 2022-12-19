1. 首先当n为1的时候，直接得到["0","1","8"]
2. 当n为2的时候，得到["00","11","69","88","96"],但是由于“00”不是数字，所以得剔除
3. 当n为3的时候，其实就是将n为2的结果，中间插入n为1时候的结果，也就是如下所示：
["101","111","181","609","619","689",...],只要把最后的结果，前缀为0的去除就可以了

所以可以总结出规律，当n大于2的时候，都是将n等于2的结果，中间夹上n-2时的结果，这样就可以使用递归了,其中递归的中间值，可以使用HashMap来暂存。

```
import java.util.*;

class Solution {
    public List<String> findStrobogrammatic(int n) {
        if (n==1){
            return Arrays.asList(new String[]{"0","1","8"});
        }
        HashMap<Integer,List<String>> map = new HashMap<>();
        List<String> strings = find(n,map);// 这个是递归的处理方法
        Iterator<String> iterator = strings.iterator();//通过迭代器去除以0开头的字符串
        while (iterator.hasNext()){
            if (iterator.next().startsWith("0")){
                iterator.remove();
            }
        }
        return strings;
    }

    public List<String> find(int n,HashMap map) {
        if (map.containsKey(n)){
            return (List<String>) map.get(n);
        }
        if (n==1){
            List<String> list = new ArrayList<>();
            list.add("0");
            list.add("1");
            list.add("8");
            map.put(1,list);
            return list;
        }
        if (n==2){
            List<String> list = new ArrayList<>();
            list.add("00");
            list.add("11");
            list.add("69");
            list.add("88");
            list.add("96");
            map.put(2,list);
            return list;
        }
        List<String> list1 = find(2,map);
        List<String> list2 = find(n-2,map);
        List<String> result = new ArrayList<>();
        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list2.size(); j++) {
                result.add(list1.get(i).charAt(0)+list2.get(j)+list1.get(i).charAt(1));
            }
        }
        return result;
    }
}

```


### 解题思路
分析就再写了，基本思路都在代码的注释里面了，和其他的大神思路基本差不多的，主要就是通过hashmap从com 开始统计

### 代码

```java
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        HashMap<String,Integer> map = new HashMap<>();
        List<String> result = new ArrayList<>();
        for (String cp : cpdomains) {
            //将地址和访问次数分割
            String[] cpinfo = cp.split(" ");
            //对地址的子域名进行分割
            String[] fraps = cpinfo[1].split("\\.");
            int count = Integer.valueOf(cpinfo[0]);
            String name = "";
            /**
             * 从后面开始，如 google.mail.com 即从com-> com.mail -> com.mail.google 计算
             */
            for (int i = fraps.length-1;i>=0;i--) {
                //判断是否为com 如果不是就加上 .
               name = fraps[i] + (i<fraps.length - 1 ? "." : "" ) + name;
               //将同名map的原始值加上去
               map.put(name,map.getOrDefault(name,0)+count);
            }
        }

        //将map中的key迭代输出
        Iterator i = map.keySet().iterator();
        while (i.hasNext()) {
            String thisName = String.valueOf(i.next());
//            System.out.println(thisName+"---"+map.get(thisName));
            result.add(map.get(thisName)+" "+thisName);
        }

        return result;
        
    }

}
```
### 解题思路
1.首先对products进行字典排序
2.剔除重复的product
3.用searchWord中的前n个字母对products进行匹配
4.剔除超过范围（3个）的products

### 代码

```java
class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<List<String>> lists = new ArrayList<>();
        char[] s = searchWord.toCharArray();
        String list_char = "";
        List<String> product = new ArrayList<>();
        for(String str : products){
            if(!product.contains(str))
                product.add(str);
        }
        Collections.sort(product);
        System.out.println(product);
        for(char search : s){
            List<String> list = new ArrayList<>();
            //根据search匹配
            list_char += search;
            int len = product.size();
            int count = 0;
            for(int i = 0; i < len; i++){
                if (product.get(i).startsWith(list_char) && !list.contains(product.get(i)) && count < 3) {
                    list.add(product.get(i));
                    count = count + 1;
                }
            }
            lists.add(list);
        }
        return lists;
    }
}
```
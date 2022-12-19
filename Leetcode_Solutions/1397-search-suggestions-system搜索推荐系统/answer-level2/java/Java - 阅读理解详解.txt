#### 1. 题目分析
本题可以不使用算法直接解题，思路如下：
- 对数组排序
- 对于$searchWord$的前$k$位（简记为$s$）：
    - 遍历$products$：
        - 若$tempList$的大小为$3$，跳出循环
        - 若$products[i]$的前$min(k, products[i].length)$位与$s$相同，加入$tempList$
    - 将$tempList$加入$list$
- 返回$list$

#### 2. Coding
```java
public List<List<String>> suggestedProducts(String[] products, String searchWord) {
    List<List<String>> list = new ArrayList<>();
    // 排序
    Arrays.sort(products);
    for(int i = 1; i <= searchWord.length(); i ++){
        List<String> tempList = new ArrayList<>();      
        // 获得前i位
        String s = searchWord.substring(0, i);
        int size = 0;
        for(String product : products){
            // 判断列表大小
            if(size == 3){
                break;
            }
            // 判断前缀匹配
            if(product.substring(0, Math.min(i, product.length())).equals(s)){
                tempList.add(product);
                size ++;
            }
        }
        list.add(tempList);
    }
    return list;
}
```
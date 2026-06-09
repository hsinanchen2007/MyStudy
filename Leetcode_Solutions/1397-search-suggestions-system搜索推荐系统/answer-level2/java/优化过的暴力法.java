先排序,然后直接在单次数组中搜素是否包含当前前缀的字符串,同时统计每次匹配的个数,
可以匹配,则统计数加1,统计数等于3就退出当次循环;不能匹配的话,先看以前统计数是否为
0,统计数不为0,说明对于当前前缀,这次循环后面已经匹配不到了,继续匹配下一个前缀,
统计数为0,说明对于当前前缀,这次循环后面还有可能匹配到。我还用了一个start字段
用来保存判断下次前缀时,单次数组的起始位置。遍历的过程中更新这个前缀,比直接暴力法
要省去一些不必要的判断。
代码如下:
```
 class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<List<String>> res = new ArrayList<>();
        if (products.length == 0 || searchWord.length() == 0) {
            return res;
        }
        Arrays.sort(products);
        int count = 0;
        int start = 0;
        for (int i = 0; i < searchWord.length(); i++) {
            String prefix = searchWord.substring(0, i + 1);
            List<String> wordList = new ArrayList<>();
            for (int j = start; j < products.length; j++) {
                if (products[j].startsWith(prefix)) {
                    wordList.add(products[j]);
                    count++;
                    if (count == 3) {
                        break;
                    }
                } else {
                    if (count > 0) {
                        break;
                    }
                    start++;
                }
            }
            count = 0;
            res.add(wordList);
        }
        return res;
    }
}
```

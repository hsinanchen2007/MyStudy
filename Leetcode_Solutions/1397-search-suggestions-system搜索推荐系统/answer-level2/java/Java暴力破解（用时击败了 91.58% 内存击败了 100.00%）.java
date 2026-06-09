![image.png](https://pic.leetcode-cn.com/d2aa74f35e6bd221160dcdeacf8cc8796c92deafe1ea0440e8d6c74b1fbf4e84-image.png)

思路很简洁，首先将searchWord拆分到数组中，如传入的searchWord="string"，则该数组元素为"s","st","str","stri","strin","string"

先使用数组第一个元素进行查找，即查找products中startsWith("s")的元素，并记录匹配"s"的开始与结束index。
第二个元素查找即可使用上面的开始结束index在小范围内查找，逐步完成查找，得到结果。

```
    int begin = 0;

    int end;

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        end = products.length - 1;
        Arrays.sort(products);
        String[] searchWords = new String[searchWord.length()];
        StringBuilder sb = new StringBuilder();
        int index = 0;
        for (char c : searchWord.toCharArray()) {
            sb.append(c);
            searchWords[index++] = sb.toString();
        }

        List<List<String>> ans = new ArrayList<>();
        for (String str : searchWords) {
            ans.add(getList(products, str));
        }
        return ans;
    }

    private List<String> getList(String[] products, String str) {
        List<String> list = new ArrayList<>();
        boolean flag = false;
        for (int i = begin; i <= end; i++) {
            if (products[i].startsWith(str)) {
                if (!flag) {
                    begin = i;
                }
                flag = true;
                if (list.size() < 3) {
                    list.add(products[i]);
                } else {
                    break;
                }
            } else {
                if (flag) {
                    end = i;
                    break;
                }
            }
        }
        return list;
    }
```

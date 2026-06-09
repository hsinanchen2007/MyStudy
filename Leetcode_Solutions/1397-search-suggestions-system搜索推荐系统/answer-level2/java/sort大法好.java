```java
    // 先searchWord进行比较，然后排序，然后以刚才的结果为基准再比较
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        int searchLen = searchWord.length();
        int productLen = products.length;
        List<List<String>> sugPros = new ArrayList<>(searchLen);
        for(int i = 0; i < searchLen; i ++) {
            int point = 0;
            List<String> sugPro = new ArrayList<>(3);
            for(int j = 0; j < productLen; j ++) {
                if(i < products[j].length() && searchWord.charAt(i) == products[j].charAt(i)) {
                    products[point ++] = products[j];
                }
            }
            Arrays.sort(products, 0, point);
            for(int j = 0; j < point && j < 3; j ++) {
                sugPro.add(products[j]);
            }
            productLen = point;
            sugPros.add(sugPro);
        }
        return sugPros;
    }
```
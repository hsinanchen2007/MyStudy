public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<String> list = Arrays.asList(products);
        Collections.sort(list);

        List<List<String>> result = new ArrayList<>();
        for (int i = 0; i < searchWord.length(); i++){
            List<String> subRes = new ArrayList<>();
            for (String s : list) {
                boolean b = s.startsWith(searchWord.substring(0, i + 1));
                if (b && subRes.size() < 3) {
                    subRes.add(s);
                }
            }
            result.add(i, subRes);
        }
        return result;
    }

for循环挺香的
```
    private List<String> list = new LinkedList<>();

    public String[] permutation(String S) {
        char[] array = S.toCharArray();
        dfs(array, new StringBuilder());

        String[] res = new String[list.size()];
        return list.toArray(res);
    }

    private void dfs (char[] array, StringBuilder builder) {
        if (builder.length() == array.length) {
            list.add(builder.toString());
            return;
        }

        for (char c : array) {
            if (builder.toString().contains(String.valueOf(c))) {
                continue;
            }

            builder.append(c);
            dfs(array, builder);
            builder.deleteCharAt(builder.length() - 1);
        }
    }
```

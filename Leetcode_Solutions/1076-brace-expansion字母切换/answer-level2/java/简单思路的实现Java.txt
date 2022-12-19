个人的笨方法，写完比赛都结束了。太菜了
```
    public String[] permute(String S) {
        S = S.replaceAll(",", "");

        List<List<String>> list = new ArrayList<>();
        int start = 0, end = start;

        // 先遍历字符串
        while (start < S.length()){
            List<String> temp = new ArrayList<>();
            char character = S.charAt(start);
            // 遇到花括号，其中的字符就单个保存
            if (character == '{'){
                end = start+1;
                while (end < S.length()){
                    temp.add(Character.toString(S.charAt(end++)));
                    if (S.charAt(end) == '}'){
                        break;
                    }
                }
                start = end+1;
                // 因为要按字典顺序，所以这里排序一下
                Collections.sort(temp);
                list.add(temp);
            }else {
                // 若不是花括号，则将这些字符连在一起，作为一个String放在list中
                StringBuilder sb = new StringBuilder();
                sb.append(character);
                end = start + 1;
                while (end < S.length()){
                    if (S.charAt(end) == '{'){
                        temp.add(sb.toString());
                        break;
                    }else {
                        sb.append(S.charAt(end++));
                    }
                }
                if (end == S.length()){
                    temp.add(sb.toString());
                }
                start = end;
                list.add(temp);
            }
        }

        // 遍历前面的list
        List<String> result = new ArrayList<>(list.get(0));
        for (int j = 1; j < list.size(); j++) {
            List<String> temp1 = list.get(j);
            List<String> temp2 = new ArrayList<>();
            // 如果遇到只存了一个String的list，则将result中的String挨个与其进行拼接
            if (temp1.size() == 1){
                for (String s: result) {
                    s += temp1.get(0);
                    temp2.add(s);
                }
            }else {
                // 如果遇到是包含了多个字母的list，则嵌套遍历，按顺序拼接，存入temp2集合中
                for (String s1:result) {
                    for (String s2: temp1) {
                        // 这里要注意，需要先复制一下，然后再拼接，不能直接拼接。
                        String temps = s1;
                        temps += s2;
                        temp2.add(temps);
                    }
                }
            }
            result.clear();
            result.addAll(temp2);
        }

        // 创建一个字符串数组，将集合中的String复制到数组中
        String[] res = new String[result.size()];
        for (int i = 0; i < result.size(); i++) {
            res[i] = result.get(i);
        }

        return res;
    }
```
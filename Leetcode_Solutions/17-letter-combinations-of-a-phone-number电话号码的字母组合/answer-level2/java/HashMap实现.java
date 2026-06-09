```
public List<String> letterCombinations(String digits) {
        if (digits.equals("")){return new ArrayList<>();}
        HashMap<String, String[]> map = new HashMap<>();
        map.put("2", new String[]{"a", "b", "c"});
        map.put("3", new String[]{"d", "e", "f"});
        map.put("4", new String[]{"g", "h", "i"});
        map.put("5", new String[]{"j", "k", "l"});
        map.put("6", new String[]{"m", "n", "o"});
        map.put("7", new String[]{"p", "q", "r", "s"});
        map.put("8", new String[]{"t", "u", "v"});
        map.put("9", new String[]{"w", "x", "y", "z"});

        ArrayList<String> sum_List = new ArrayList<>();
        sum_List.add("");
        int list_len = 1;
        int list_size = 1;
        for (int i = 0; i < digits.length(); i++){
            String[] char_list =  map.get(digits.substring(i, i+1));
            ArrayList<String> char_List = new ArrayList<>();
            for (int j = 0; j < list_len; j++){
                for (int k = 0; k < char_list.length; k++){
                    String temp = sum_List.get(j) + char_list[k];
                    char_List.add(temp);
                }
            }
            list_len = char_List.size();
            sum_List = char_List;
        }

        return sum_List;
    }
```
![FireShot Capture 021 - 17. 电话号码的字母组合 - 力扣（LeetCode） - leetcode-cn.com.png](https://pic.leetcode-cn.com/1c8adbe3f6f5882d26cbf0e5cbce5a4d5740565cf4ed2604ca2b6ee4ed209f2e-FireShot%20Capture%20021%20-%2017.%20%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E5%AD%97%E6%AF%8D%E7%BB%84%E5%90%88%20-%20%E5%8A%9B%E6%89%A3%EF%BC%88LeetCode%EF%BC%89%20-%20leetcode-cn.com.png)


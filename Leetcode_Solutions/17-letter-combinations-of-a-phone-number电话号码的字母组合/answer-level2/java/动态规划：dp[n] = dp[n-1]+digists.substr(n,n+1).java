先把digists的第一个数字取出来，有三种或者四种结果，每次新增一个数字的时候，结果都等于前一次的结果的list+当前数字的list遍历相加
```
public List<String> letterCombinations(String digits) {
        if(digits == null || digits.length() == 0){
            return Collections.emptyList();
        }
        Map<Integer, List<String>> map = new HashMap<>();
        map.put(2, Arrays.asList("a", "b", "c"));
        map.put(3, Arrays.asList("d", "e", "f"));
        map.put(4, Arrays.asList("g", "h", "i"));
        map.put(5, Arrays.asList("j", "k", "l"));
        map.put(6, Arrays.asList("m", "n", "o"));
        map.put(7, Arrays.asList("p", "q", "r", "s"));
        map.put(8, Arrays.asList("t", "u", "v"));
        map.put(9, Arrays.asList("w", "x", "y", "z"));
        List<List<String>> dp = new ArrayList<>();

        dp.add(map.get(Integer.valueOf(digits.substring(0,1))));
        for(int i = 1; i < digits.length(); i++){
            List<String> list = new ArrayList<>();
            List<String> before = dp.get(i-1);
            List<String> now = map.get(Integer.valueOf(digits.substring(i, i+1)));
            for(int j = 0; j < now.size(); j++){
                for(int k = 0; k < before.size(); k++){
                    list.add(before.get(k)+now.get(j));
                }
            }
            dp.add(list);
        }
        return dp.get(dp.size()-1);
    }

```

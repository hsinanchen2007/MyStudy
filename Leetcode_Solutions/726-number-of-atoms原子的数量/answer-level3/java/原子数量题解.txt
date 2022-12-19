首先，分析原子表达式的特点，在原子表达式中只有英文大写，英文小写，左括号，右括号和数字五种情况。在解析过程中一个完整的表达式一定以英文大写或者左括号开头，当遍历到下一个字符是大写字母或者左括号时，一个完整的子表达式结束；
然后，我们采用分治的策略，依次求解一个长串原子表达式中的各个独立的子表达式，子表达式再依次分解子子表达式，直到最后分解的表达式中没有括号为止。例如：Mg(OH)2分解为Mg、O*2和H*2；
最后，将上一步中的子表达式合并产生当前表达式的结果，直到合并到最上层为止。

```
class Solution {
    public String countOfAtoms(String formula) {
        Map<String, Integer> map = calculateParenthesis(1, formula);
        String result = "";
        for (Map.E***y<String, Integer> e***y : map.e***ySet()) {
            if(1 == e***y.getValue()){
                result = result + e***y.getKey();
            }else{
                result = result + e***y.getKey() + e***y.getValue();
            }
        }
        return result;
    }
    
    public Map<String, Integer> calculateParenthesis(Integer multiplier, String formula){
        List<Map<String, Integer>> list = new LinkedList<Map<String, Integer>>();
        int i = 0;
        while(i < formula.length()){
            if(String.valueOf(formula.charAt(i)).equals("(")){
                int balance = 1;
                int j = i +1;
                while(j < formula.length() && balance > 0){
                    if(String.valueOf(formula.charAt(j)).equals("(")){
                        balance++;
                    }else if (String.valueOf(formula.charAt(j)).equals(")")){
                        balance--;
                    }
                    j++;
                }
                String str = formula.substring(i+1, j-1);
                Integer count = 1;
                if(j <  formula.length() && Character.isDigit(formula.charAt(j))){
                    int k = j + 1;
                    while (k < formula.length() && Character.isDigit(formula.charAt(k))){
                        k++;
                    }
                    count = Integer.valueOf(formula.substring(j, k));
                    j = k;
                }
                list.add(calculateParenthesis(count, str));
                i = j;
            } else if (Character.isUpperCase(formula.charAt(i))){
                Map<String, Integer> map = new HashMap<String, Integer>();
                int j = i + 1;
                while(j < formula.length() && Character.isLowerCase(formula.charAt(j))){
                    j++;
                }
                String atom = formula.substring(i, j);
                Integer count = map.get(atom);
                if(count == null){
                    count = 0;
                }
                if(j < formula.length() && Character.isDigit(formula.charAt(j))){
                    int k = j + 1;
                    while(k < formula.length() && Character.isDigit(formula.charAt(k))){
                        k++;
                    }
                    count = count + Integer.valueOf(formula.substring(j, k));
                    i = k;
                }else{
                    count = count + 1;
                    i = j;
                }
                map.put(atom, count);
                list.add(map);
            }
        }
        Map<String, Integer> map = new TreeMap<String, Integer>(
                new Comparator<String>() {
                    public int compare(String obj1, String obj2) {
                        return obj1.compareTo(obj2);
                    }
                });
        for (Map<String, Integer> m : list){
            for (Map.E***y<String, Integer> e***y : m.e***ySet()){
                if (map.get(e***y.getKey()) != null){
                    map.put(e***y.getKey(), e***y.getValue() * multiplier + map.get(e***y.getKey()));
                }else {
                    map.put(e***y.getKey(), e***y.getValue() * multiplier);
                }
            }
        }
        return map;
    }
}
```
```java
class Solution {
    private Map<String, List<Integer>> cache = new HashMap<>();

    public List<Integer> diffWaysToCompute(String input) {
        if (input == null || input.length() == 0) {
            return Collections.emptyList();
        }
        return compute(input, 0, input.length());
    }

    private List<Integer> compute(String input, int start, int end) {
        String s = input.substring(start, end);
        if (cache.containsKey(s)) {
            return cache.get(s);
        }
        char c;
        List<Integer> list = new ArrayList<>();
        for (int i = start; i < end; i++) {
            c = input.charAt(i);
            if (isOperator(c)) {
                List<Integer> left = compute(input, start, i);
                List<Integer> right = compute(input, i + 1, end);
                list.addAll(getAns(left, right, c));
            }
        }
        if (list.isEmpty()) {
            list.add(Integer.parseInt(input.substring(start, end)));
        }
        cache.put(s, list);
        return list;
    }

    private boolean isOperator(char c) {
        return c == '+' || c == '-' || c == '*';
    }

    private List<Integer> getAns(List<Integer> left, List<Integer> right, char c) {
        List<Integer> ans = new ArrayList<>(left.size() * right.size());
        for (Integer l : left) {
            for (Integer r : right) {
                switch (c) {
                    case '+':
                        ans.add(l + r);
                        break;
                    case '-':
                        ans.add(l - r);
                        break;
                    default:
                        ans.add(l * r);
                }
            }
        }
        return ans;
    }

    
}
```

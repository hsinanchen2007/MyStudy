```java
class Solution {
    public Integer calculate(Integer a, Integer b, Character operator) {
        if (operator.equals('+'))
            return a+b;
        else if (operator.equals('-'))
            return a-b;
        else
            return a*b;
    }
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> num = new ArrayList<>();
        List<Character> operator = new ArrayList<>();
        // separate num & operator
        int tmpNum = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '+' || input.charAt(i) == '-' || input.charAt(i) == '*') {
                num.add(tmpNum);
                tmpNum = 0;
                operator.add(input.charAt(i));
            } else {
                tmpNum = tmpNum * 10 + (input.charAt(i) - '0');
            }    
        }
        num.add(tmpNum);
        // dp
        List<Integer>[][] res = new ArrayList[num.size()][num.size()];
        for (int i = 0; i < num.size(); i++)
            res[i][i] = new ArrayList<>(Arrays.asList(num.get(i)));
        for (int k = 1; k < num.size(); k++)
            for (int i = 0; i < num.size() - k; i++) {
                List<Integer> combine = new ArrayList<>();
                for (int j = 0; j < k; j++) {
                List<Integer> leftNumList = res[i][i+j];  
                List<Integer> rightNumList = res[i+j+1][i+k];
                for (Integer leftNum : leftNumList) 
                    for (Integer rightNum : rightNumList)
                        combine.add(calculate(leftNum, rightNum, operator.get(i+j)));
                res[i][i+k] = new ArrayList(combine);
                }
            }
        return res[0][num.size()-1];
    }
}
```
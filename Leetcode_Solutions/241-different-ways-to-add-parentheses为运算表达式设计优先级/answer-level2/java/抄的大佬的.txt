    
    class Solution {
        public List<Integer> diffWaysToCompute(String input) {
            List<Integer> res = new ArrayList<>();
            for(int i = 0;i < input.length();i++) {
                if(!(input.charAt(i) >= '0' && input.charAt(i) <= '9')) {
                    List<Integer> list1 = diffWaysToCompute(input.substring(0, i));
                    List<Integer> list2 = diffWaysToCompute(input.substring(i + 1));
                    for(Integer num1 : list1) {
                        for(Integer num2 : list2) {
                            switch (input.charAt(i)) {
                            case '+':
                                res.add(num1 + num2);
                                break;
                            case '-':
                                res.add(num1 - num2);
                                break;
                            case '*':
                                res.add(num1 * num2);
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }
            }
            if(res.isEmpty()) {
                res.add(Integer.parseInt(input));
            }
            return res;
        }
    }
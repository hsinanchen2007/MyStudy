```
class Solution {
    private final String[] STRINGS = new String[] {"Hundred", "Thousand", "Million", "Billion"};

    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        StringBuilder builder = new StringBuilder();
        LinkedList<String> stack = new LinkedList<>();
        //数量级指示
        int index = 0;
        while (num > 0) {
            int hundred = num % 1000;
            num /= 1000;
            int singleDigit = hundred % 10;
            int tensDigit = hundred % 100;
            int hundredsDigit = hundred / 100;

            if (index > 0) {
                if (hundred > 0) {
                    stack.addLast(STRINGS[index]);
                    stack.addLast(" ");
                }
            }

            if (tensDigit < 20) {
                if (tensDigit > 0) {
                    stack.addLast(oneToNineteen(tensDigit));
                    stack.addLast(" ");
                }
            } else {
                if (singleDigit > 0) {
                    stack.addLast(oneToNineteen(singleDigit));
                    stack.addLast(" ");
                    stack.addLast(twentyToNinety(tensDigit - singleDigit));
                    stack.addLast(" ");
                } else {
                    stack.addLast(twentyToNinety(tensDigit - singleDigit));
                    stack.addLast(" ");
                }
            }
            if (hundredsDigit > 0) {
                stack.addLast(STRINGS[0]);
                stack.addLast(" ");
                stack.addLast(oneToNineteen(hundredsDigit));
                stack.addLast(" ");
            }

            index++;
        }
        //去除最后的空格符
        stack.removeLast();

        while (!stack.isEmpty()) {
            builder.append(stack.removeLast());
        }

        return builder.toString();
    }

    private String oneToNineteen(int num) {
        switch (num) {
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
            case 10:
                return "Ten";
            case 11:
                return "Eleven";
            case 12:
                return "Twelve";
            case 13:
                return "Thirteen";
            case 14:
                return "Fourteen";
            case 15:
                return "Fifteen";
            case 16:
                return "Sixteen";
            case 17:
                return "Seventeen";
            case 18:
                return "Eighteen";
            case 19:
                return "Nineteen";
            default:
                throw new IllegalArgumentException(String.valueOf(num));
        }
    }

    private String twentyToNinety(int num) {
        switch (num) {
            case 20:
                return "Twenty";
            case 30:
                return "Thirty";
            case 40:
                return "Forty";
            case 50:
                return "Fifty";
            case 60:
                return "Sixty";
            case 70:
                return "Seventy";
            case 80:
                return "Eighty";
            case 90:
                return "Ninety";
            default:
                throw new IllegalArgumentException(String.valueOf(num));
        }
    }
}
```

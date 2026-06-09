![image.png](https://pic.leetcode-cn.com/c1e191aa5bf1407baf5628ac38a80f00be3b6d7faa256f81e637a0e405ee3be2-image.png)

public  List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();

        if (n == 0) {
            return result;
        }

        generate(n, result, "", 0, 0);
        return result;

    }

    private  void generate(int n, List<String> result, String item, int left, int right) {

        if ((left + right) == 2 * n) {
            result.add(item);
        }

        if (left < n) {
            generate(n, result, item + "(", left + 1, right);
        }

        if ((right < n) && (right < left)) {
            generate(n, result, item + ")", left, right + 1);
        }
    }
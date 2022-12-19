![image.png](https://pic.leetcode-cn.com/01a6bd9d95e217c65e9e7a51785a70ecd80ef9e8b791b63ac3a74e74738134c1-image.png)


public static List<String> ambiguousCoordinates(String S) {

        // 去掉 "(" and ")"
        String str = S.substring(1, S.length() - 1);

        List<String> result = new LinkedList<>();
        for (int i = 1; i < str.length(); i++) {
            String left = str.substring(0, i);
            String right = str.substring(i, str.length());

            List<String> leftNums = getNumbers(left);
            List<String> rightNums = getNumbers(right);

            //
            if (rightNums.size() == 0 || leftNums.size() == 0) {
                continue;
            }

            for (String lNum : leftNums) {
                for (String rNum : rightNums) {
                    StringBuffer sb = new StringBuffer();
                    sb.append("(");
                    sb.append(lNum);
                    sb.append(", ");
                    sb.append(rNum);
                    sb.append(")");

                    result.add(sb.toString());
                }

            }

        }

        return result;

    }

    private static List<String> getNumbers(String str) {
        List<String> result = new LinkedList<>();

        // 单个数字
        if (str.length() == 1) {

            result.add(str);
            return result;
        }

        // 整数的情况
        if (!str.startsWith("0")) {
            result.add(str);
        }

        // 以下开始小数点的组合

        // 0开头的，第二位一定是小数点，结尾不能为0，只有一种组合，返回
        if (str.startsWith("0") && !str.endsWith("0")) {
            StringBuffer sb = new StringBuffer();
            sb.append("0.");
            sb.append(str.substring(1, str.length()));
            result.add(sb.toString());
            return result;
        }

        if (!str.endsWith("0")) {
            // 小数点组合
            for (int i = 1; i < str.length(); i++) {
                StringBuffer temp = new StringBuffer();
                temp.append(str.substring(0, i));
                temp.append(".");
                temp.append(str.substring(i, str.length()));
                result.add(temp.toString());

            }
        }

        return result;

    }

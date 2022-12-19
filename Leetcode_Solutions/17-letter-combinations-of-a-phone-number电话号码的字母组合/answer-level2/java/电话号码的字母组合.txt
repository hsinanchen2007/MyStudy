解题思路：
递归思路：对于最简单的两个数字，使用全排列可以求得全部字母组合。那么对于多个电话号码，刚开始我们将第一个号码与第二个号码的组合求出来。然后将这次结果与下个电话号码再次求全排列组合，以此类推当到达电话号码最后一位时就是整个电话号码的字母组合。
例如：
电话号码"23"，全排列组合结果为res1,那么"234"的结果就是res1与'4'对应的字符进行全排列的结果。
代码如下：
```
 public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits.equals(""))
            return res;
        String nums1 = null;
        String nums2 = null;
        if (digits.length() == 1){
            char first = digits.charAt(0);
            switch (first){
                case '2': nums1 = "abc";
                    break;
                case '3': nums1 = "def";
                    break;
                case '4': nums1 = "ghi";
                    break;
                case '5': nums1 = "jkl";
                    break;
                case '6': nums1 = "mno";
                    break;
                case '7': nums1 = "pqrs";
                    break;
                case '8': nums1 = "tuv";
                    break;
                case '9': nums1 = "wxyz";
                    break;
                default: nums1 = "";
            }
            for (int i = 0; i < nums1.length(); i++) {
                res.add(nums1.charAt(i) + "");
            }
            return res;
        }

        for (int i = 1; i < digits.length(); i++) {
            char first = digits.charAt(i - 1);
            char second = digits.charAt(i);
            if (i == 1){
                switch (first){
                    case '2': nums1 = "abc";
                        break;
                    case '3': nums1 = "def";
                        break;
                    case '4': nums1 = "ghi";
                        break;
                    case '5': nums1 = "jkl";
                        break;
                    case '6': nums1 = "mno";
                        break;
                    case '7': nums1 = "pqrs";
                        break;
                    case '8': nums1 = "tuv";
                        break;
                    case '9': nums1 = "wxyz";
                        break;
                    default: nums1 = "";
                }
            }
            switch (second){
                case '2': nums2 = "abc";
                    break;
                case '3': nums2 = "def";
                    break;
                case '4': nums2 = "ghi";
                    break;
                case '5': nums2 = "jkl";
                    break;
                case '6': nums2 = "mno";
                    break;
                case '7': nums2 = "pqrs";
                    break;
                case '8': nums2 = "tuv";
                    break;
                case '9': nums2 = "wxyz";
                    break;
                default: nums2 = "";
            }
            if (res.size() == 0){
                for (int j = 0; j < nums1.length(); j++) {
                    for (int k = 0; k < nums2.length(); k++) {
                        res.add(nums1.charAt(j) + "" + nums2.charAt(k));
                    }
                }
            }else{
                List<String> strings = new ArrayList<>();
                for (int j = 0; j < res.size(); j++) {
                    for (int k = 0; k < nums2.length(); k++) {
                        strings.add(res.get(j) + nums2.charAt(k));
                    }
                }
                res = strings;
            }
        }
        return res;
    }
```
时间复杂度：3 ** N，其中N为电话号码位数；
空间复杂度：N
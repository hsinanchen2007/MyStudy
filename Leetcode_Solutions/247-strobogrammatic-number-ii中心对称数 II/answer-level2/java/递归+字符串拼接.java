思路：
将结果s一分为二
String s = start + end;
递归情况 ： 
    1. start+"0"+"0"+end（1/8也成立）
    2. start+"6"+"9"+end
    3. start+"9"+"6"+end


可以设置布尔变量判断是否为首次递归，毕竟0开头算的次数占了1/5
```
class Solution {
        List<String> list = new ArrayList<>();
        //上下对称的数字
        String[] number = new String[]{"1", "8", "0"};
        public List<String> findStrobogrammatic(int n) {
            if (n <= 0) {
                return list;
            }
            String start = "";
            String end = "";
            findStrobogrammatic(start, end, n);
            return list;
        }

        private void findStrobogrammatic(String start, String end, int n) {
            //1.递归终止条件
            if (n == 0) {
                if (start.length() != 0 && end.length() != 0 && !start.startsWith("0"))
                    list.add(start + end);
                return;
            }
            if (n == 1) {
                for (int i = 0; i < number.length; i++) {
                    String temp = start + number[i] + end;
                    if (!start.startsWith("0"))
                        list.add(temp);
                }
                return;
            }
            //2.当前递归层处理逻辑在于参数start以及end的变化
            //3.往下一层递归
            for (int i = 0; i < number.length; i++) {
                findStrobogrammatic(start + number[i], number[i] + end, n - 2);
            }
            //69做特殊处理
            findStrobogrammatic(start + "6", "9" + end, n - 2);
            findStrobogrammatic(start + "9", "6" + end, n - 2);
        }
    }
```

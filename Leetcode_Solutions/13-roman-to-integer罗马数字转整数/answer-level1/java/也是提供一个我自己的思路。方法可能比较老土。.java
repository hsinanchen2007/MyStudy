class Solution {
    public int romanToInt(String s) {
        HashMap<String,Integer> map = new HashMap();
        int answer = 0;
        int i;
        map.put("I", 1);
        map.put("V", 5);
        map.put("X", 10);
        map.put("L", 50);
        map.put("C", 100);
        map.put("D", 500);
        map.put("M", 1000);
        //首先还是将出现的6个数放进哈希中，等待匹配。
        //有一种情况是可能越界，只要我们在循环时少执行一次.在末尾直接加上那个数就可以了。
        for (i = 0; i < s.length()-1; i++) {
            //然后我们循环遍历待计算的字符串，计算之前，先判断6种特殊情况。每2种情况一组，一共三组情况。就是题目中说的情况。这样直观的理解
            if (("I".equals(s.substring(i,i+1)) &&
                    ("V".equals(s.substring(i+1,i+2)) || "X".equals(s.substring(i+1,i+2))))
                    //出现这种情况就减去当前那个数值，否则就加上。
                    || ("X".equals(s.substring(i,i+1)) &&
                    ("L".equals(s.substring(i+1,i+2)) || "C".equals(s.substring(i+1,i+2))))
                    //出现这种情况就减去当前那个数值，否则就加上。
                    || ("C".equals(s.substring(i,i+1)) &&
                    ("D".equals(s.substring(i+1,i+2)) || "M".equals(s.substring(i+1,i+2))))){
                answer = answer - map.get(s.substring(i,i+1));
            }else {
                answer = answer + map.get(s.substring(i,i+1));
            }
        }
        // 加上最后一个数
        answer = answer + map.get(s.substring(s.length()-1,s.length()));
        // 我自己在idea里测试过了。但是这种题目没有考虑非法输入。其实也同理，匹配不成功直接抛出异常。
        return answer;
    }
}